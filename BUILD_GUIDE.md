# Tài liệu Hướng dẫn Phát triển và Build LaMoKey (Đa nền tảng)

Tài liệu này cung cấp hướng dẫn chi tiết cách thiết lập môi trường, phát triển và biên dịch (build) dự án **LaMoKey** trên 3 nền tảng chính: **macOS, Windows và Linux**.

---

## 1. Cấu trúc mã nguồn

Mã nguồn được chia thành các phần sau:
- `engine/`: (Core Engine C++) Chứa toàn bộ logic xử lý gõ tiếng Việt, bảng mã, kiểu gõ (Telex, VNI), macro gõ tắt. Được chia sẻ dùng chung cho cả 3 nền tảng.
- `macOS/`: Giao diện ứng dụng và service cho nền tảng macOS (Objective-C/Swift).
- `win32/`: Giao diện ứng dụng và service cho nền tảng Windows (C++ Win32 API).
- `linux/`: Input Method Engine (IME) client cho nền tảng Linux, giao tiếp thông qua **IBus** framework (C/C++).

---

## 2. Hướng dẫn Build trên macOS

**Yêu cầu hệ thống:**
- Hệ điều hành: macOS Mojave trở lên.
- Công cụ: XCode 10 trở lên.

**Các bước thực hiện:**
1. Mở thư mục `macOS/`.
2. Mở file project `LaMoKey.xcodeproj` bằng phần mềm XCode.
3. Chọn Target là `LaMoKey` hoặc `LaMoKeyHelper` tùy vào mục đích phát triển.
4. Chọn thiết bị đích là *My Mac*.
5. Nhấn `Cmd + B` để tiến hành Build. 
6. Để đóng gói bản phát hành (Production), chọn **Product -> Archive** trên thanh menu của XCode, sau đó chọn **Distribute App -> Copy App** để xuất file `LaMoKey.app`.

*Lưu ý:* Ứng dụng yêu cầu quyền **Accessibility**. Nếu chạy từ XCode, bạn cần cấp quyền Accessibility cho XCode trong *System Settings -> Privacy & Security -> Accessibility*.

---

## 3. Hướng dẫn Build trên Windows

**Yêu cầu hệ thống:**
- Hệ điều hành: Windows 10/11.
- Công cụ: Visual Studio (Khuyến nghị bản 2019 trở lên) có cài đặt workload **"Desktop development with C++"**.
- Windows 10 SDK.

**Các bước thực hiện:**
1. Mở thư mục `win32/LaMoKey/`.
2. Mở file solution `LaMoKey.sln` bằng Visual Studio.
3. Trên thanh công cụ, chọn cấu hình build là `Release` (hoặc `Debug` nếu bạn đang tìm lỗi) và kiến trúc `x86` hoặc `x64`.
4. Nhấn **Build -> Build Solution** (hoặc nhấn `Ctrl + Shift + B`).
5. Nếu quá trình thành công, tệp tin thực thi `LaMoKey.exe` sẽ được sinh ra ở trong thư mục con `Release` (hoặc `Debug`).

---

## 4. Hướng dẫn Build trên Linux

Phiên bản Linux của LaMoKey sử dụng kiến trúc giao tiếp với **Fcitx5** framework, là bộ khung xử lý đầu vào thế hệ mới, hiện đại và được ưa chuộng rộng rãi bởi cộng đồng người dùng Linux.

**Yêu cầu hệ thống:**
- Hệ điều hành: Linux (Ubuntu, Arch Linux, Fedora...).
- Các gói cài đặt cần thiết: `cmake`, `g++`, `fcitx5-devel`, `extra-cmake-modules`.
  *(Ví dụ trên Ubuntu/Debian: `sudo apt install cmake g++ fcitx5 fcitx5-modules-dev extra-cmake-modules`)*
  *(Ví dụ trên Arch Linux: `sudo pacman -S cmake gcc fcitx5 extra-cmake-modules`)*

**Các bước thực hiện:**
1. Mở Terminal và di chuyển vào thư mục `linux/`.
   ```bash
   cd linux
   ```
2. Tạo thư mục build và cấu hình với CMake:
   ```bash
   mkdir build
   cd build
   cmake ..
   ```
3. Tiến hành biên dịch (tạo ra thư viện `lamokey.so`):
   ```bash
   make
   ```
4. Cài đặt vào hệ thống (Yêu cầu quyền root):
   ```bash
   sudo make install
   ```
   *Lệnh này sẽ copy file thư viện addon vào thư mục cài đặt addon của Fcitx5 (`/usr/lib/fcitx5/`) và các file cấu hình vào `/usr/share/fcitx5/`.*

5. Khởi động lại Fcitx5 để nhận diện bộ gõ LaMoKey:
   ```bash
   fcitx5 -r
   ```
   Sau đó, mở công cụ cấu hình `fcitx5-configtool`, thêm bộ gõ **LaMoKey** vào danh sách "Input Method" (Current Input Method) để bắt đầu sử dụng.

### Đóng gói (Tạo file cài đặt .deb / .rpm)
LaMoKey hỗ trợ tạo sẵn file cài đặt cho các bản phân phối Linux phổ biến thông qua CPack.
Sau khi đã chạy lệnh `cmake ..` bên trong thư mục `build`, thay vì gọi `make install`, bạn có thể chạy:
```bash
make package
```
Lệnh này sẽ tự động đóng gói toàn bộ thư viện và cấu hình thành các file `fcitx5-lamokey-1.0.0.deb` và `fcitx5-lamokey-1.0.0.rpm`. Bạn có thể gửi file này cho người dùng khác để họ nháy đúp chuột cài đặt một cách dễ dàng mà không cần phải compile lại từ đầu.

---

## 5. Đóng góp mã nguồn (Contributing)

Nếu bạn muốn đóng góp để khắc phục lỗi (Bug fixes) hoặc phát triển tính năng mới:
1. Luôn thực hiện logic thay đổi bên trong thư mục `engine/` nếu nó ảnh hưởng đến logic tiếng Việt (như vậy cả 3 nền tảng sẽ tự động được hưởng lợi).
2. Kiểm tra việc build kỹ trên cả 3 nền tảng nếu thay đổi liên quan đến API của `engine/`.
3. Ghi rõ các thay đổi vào `CHANGELOG.md` và tạo Pull Request.
