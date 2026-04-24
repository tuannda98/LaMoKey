#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>

#ifndef LAMOKEY_VERSION
#define LAMOKEY_VERSION "0.0.0"
#endif
#ifndef LAMOKEY_VERSION_CODE
#define LAMOKEY_VERSION_CODE 0
#endif

static std::string trim(const std::string &value) {
    size_t start = 0;
    while (start < value.size() && std::isspace(static_cast<unsigned char>(value[start]))) {
        ++start;
    }
    size_t end = value.size();
    while (end > start && std::isspace(static_cast<unsigned char>(value[end - 1]))) {
        --end;
    }
    return value.substr(start, end - start);
}

static std::string runCommand(const char *command) {
    std::array<char, 256> buffer;
    std::string result;
    FILE *pipe = popen(command, "r");
    if (!pipe) {
        return result;
    }
    while (fgets(buffer.data(), buffer.size(), pipe) != nullptr) {
        result += buffer.data();
    }
    pclose(pipe);
    return result;
}

static bool fetchRemoteJson(std::string &json) {
    static const char *commands[] = {
        "curl -fsSL https://raw.githubusercontent.com/tuannda98/LaMoKey/main/version.json",
        "wget -qO- https://raw.githubusercontent.com/tuannda98/LaMoKey/main/version.json"
    };
    for (const char *cmd : commands) {
        json = runCommand(cmd);
        if (!json.empty()) {
            return true;
        }
    }
    return false;
}

static bool parseJsonField(const std::string &json, const std::string &field, std::string &out) {
    auto pos = json.find(field);
    if (pos == std::string::npos) {
        return false;
    }
    pos = json.find(':', pos);
    if (pos == std::string::npos) {
        return false;
    }
    ++pos;
    while (pos < json.size() && std::isspace(static_cast<unsigned char>(json[pos]))) {
        ++pos;
    }
    if (pos >= json.size()) {
        return false;
    }
    if (json[pos] == '"') {
        ++pos;
        auto endPos = json.find('"', pos);
        if (endPos == std::string::npos) {
            return false;
        }
        out = json.substr(pos, endPos - pos);
        return true;
    }
    auto endPos = json.find_first_of(",}\n", pos);
    if (endPos == std::string::npos) {
        endPos = json.size();
    }
    out = trim(json.substr(pos, endPos - pos));
    return true;
}

static bool parseLatestLinuxVersion(const std::string &json, std::string &versionName, int &versionCode) {
    auto pos = json.find("latestLinuxVersion");
    if (pos == std::string::npos) {
        return false;
    }
    auto begin = json.find('{', pos);
    auto end = json.find('}', begin);
    if (begin == std::string::npos || end == std::string::npos || begin >= end) {
        return false;
    }
    std::string section = json.substr(begin + 1, end - begin - 1);
    std::string codeString;
    if (!parseJsonField(section, "\"versionName\"", versionName) ||
        !parseJsonField(section, "\"versionCode\"", codeString)) {
        return false;
    }
    try {
        versionCode = std::stoi(codeString);
    } catch (...) {
        return false;
    }
    return true;
}

int main() {
    std::cout << "LaMoKey Linux update checker\n";
    std::cout << "Current version: " << LAMOKEY_VERSION << " (code=" << LAMOKEY_VERSION_CODE << ")\n";

    std::string json;
    if (!fetchRemoteJson(json)) {
        std::cerr << "Không thể tải thông tin phiên bản từ máy chủ. Vui lòng kiểm tra kết nối internet.\n";
        return 2;
    }

    std::string latestVersion;
    int latestVersionCode = 0;
    if (!parseLatestLinuxVersion(json, latestVersion, latestVersionCode)) {
        std::cerr << "Không thể phân tích file version.json. Định dạng dữ liệu không hợp lệ.\n";
        return 3;
    }

    std::cout << "Latest Linux version: " << latestVersion << " (code=" << latestVersionCode << ")\n";
    if (latestVersionCode > LAMOKEY_VERSION_CODE) {
        std::cout << "Có phiên bản mới. Vui lòng cập nhật LaMoKey Linux.\n";
        return 1;
    }

    std::cout << "Bạn đang dùng phiên bản mới nhất của LaMoKey Linux.\n";
    return 0;
}
