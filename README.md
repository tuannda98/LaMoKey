<div align="center">
  <h1>LaMoKey</h1>
  <p><strong>Bộ gõ tiếng Việt nguồn mở cho macOS</strong></p>
  
  [![GitHub release](https://img.shields.io/github/v/release/tuyenvm/LaMoKey.svg)](https://github.com/tuyenvm/LaMoKey/releases/latest)
  [![License](https://img.shields.io/badge/license-GPL-blue.svg)](LICENSE)
</div>

---

## 📖 Giới thiệu
LaMoKey là bộ gõ tiếng Việt mới cho macOS, sử dụng kỹ thuật `Backspace`. Ứng dụng giúp loại bỏ lỗi gạch chân khó chịu thường gặp ở bộ gõ mặc định của hệ điều hành. Dự án hoàn toàn miễn phí, mã nguồn mở, luôn được cập nhật và phát triển liên tục.

Mã nguồn của ứng dụng được mở công khai, minh bạch dưới giấy phép **GPL**. Điều này có nghĩa là bạn hoàn toàn có thể tải mã nguồn về tự build, cải tiến theo mục đích của mình. (Lưu ý: Nếu phân phối bản cải tiến, mã nguồn phải được mở và ghi nguồn gốc là LaMoKey).

---

## 🌟 Tính năng nổi bật
- **Hiện đại hóa dấu Tiếng Việt** (On/Off): Đặt dấu oà, uý thay vì òa, úy.
- **Gõ nhanh (Quick Telex)** (On/Off): Tự động mở rộng phụ âm (cc=ch, gg=gi, kk=kh, nn=ng, qq=qu, pp=ph, tt=th).
- **Kiểm tra thông minh**: Hỗ trợ kiểm tra ngữ pháp và chính tả.
- **Phục hồi phím**: Tự động phục hồi phím gốc nếu nhập sai từ.
- **Khởi động cùng hệ thống**: Hỗ trợ chạy ngầm cùng macOS.
- **Tùy biến giao diện**: Biểu tượng thanh menu xám phù hợp với chế độ Dark mode, hiển thị biểu tượng trên Dock.
- **Phím tắt thông minh**: Đổi chế độ gõ bằng phím tắt tùy chọn. Tạm tắt kiểm tra chính tả (Ctrl), tạm tắt LaMoKey (Cmd/Alt).
- **Sửa lỗi phổ biến**: Khắc phục lỗi autocorrect trên Chrome, Safari, Firefox, Excel, và lỗi gạch chân trên macOS.
- **Gõ tắt đa dạng (Macro)**: Tính năng gõ tắt không giới hạn ký tự (vượt qua giới hạn 20 ký tự của macOS). Có thể dùng các phím f, z, w, j làm phụ âm đầu.
- **Chuyển chế độ linh hoạt**: Tự động ghi nhớ và chuyển chế độ gõ (Anh/Việt) riêng biệt cho từng ứng dụng. Tự ghi nhớ bảng mã theo ứng dụng (VD: Photoshop dùng VNI, Word dùng Unicode).
- **Công cụ hỗ trợ**: 
  - Tự động viết hoa chữ cái đầu câu.
  - Công cụ chuyển mã văn bản nhanh chóng (VNI, TCVN3 sang Unicode...).
  - Chế độ "Gửi từng phím" để tương thích với ứng dụng cũ.
  - Tự động kiểm tra cập nhật.

---

## ⌨️ Bảng mã & Kiểu gõ hỗ trợ

### Kiểu gõ
- Telex
- VNI
- Simple Telex

### Bảng mã thông dụng
- Unicode (Unicode dựng sẵn)
- TCVN3 (ABC)
- VNI Windows
- Unicode Compound (Unicode tổ hợp)
- Vietnamese Locale CP 1258
- Và nhiều bảng mã khác...

---

## 🚀 Hướng dẫn cài đặt

### Cách 1: Cài đặt thủ công
1. Tải bản release mới nhất từ [Trang Releases](https://github.com/tuyenvm/LaMoKey/releases/latest).
2. Mở file `.dmg`.
3. Kéo thả `LaMoKey.app` vào thư mục `Applications`.

### Cách 2: Cài đặt qua Homebrew (bởi nhymxu)
Nếu chưa có Homebrew, cài đặt bằng lệnh:
```bash
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
```

Cài đặt LaMoKey:
```bash
brew install --cask lamokey
```

Để cập nhật LaMoKey lên bản mới nhất:
```bash
brew upgrade --cask lamokey
```

---

## ⚠️ Lưu ý quan trọng
1. **Tắt các bộ gõ khác**: Khi sử dụng LaMoKey, bạn nên tắt hẳn bộ gõ khác (kể cả bộ gõ mặc định) vì hai chương trình bộ gõ chạy song song sẽ gây xung đột, dẫn đến nhập liệu không chính xác.
2. **Cấp quyền hệ thống**: LaMoKey cần được cấp quyền Accessibility. 
   - Truy cập: *System Preferences -> Security & Privacy -> Accessibility*, kích hoạt `LaMoKey.app`. 
   - **Không tắt quyền này khi đang sử dụng LaMoKey**.

---

## 📚 Tài liệu dự án
- [Hướng dẫn vận hành & Phát triển (Dành cho Lập trình viên)](BUILD_GUIDE.md)
- [Nhật ký cập nhật (Changelog)](CHANGELOG.md)

### Phiên bản nền tảng khác
- [LaMoKey cho Windows](Sources/LaMoKey/win32)
- [LaMoKey cho Linux (đang phát triển)](Sources/LaMoKey/linux)

---

## 🤝 Đóng góp & Tác giả

**Tác giả:** Mai Vũ Tuyên
- Email: maivutuyen.91@gmail.com
- Fanpage: [LaMoKeyVN trên Facebook](https://www.facebook.com/LaMoKeyVN)

Mọi đóng góp mã nguồn xin vui lòng tham khảo tài liệu [Hướng dẫn Phát triển](BUILD_GUIDE.md) và tạo Pull Request.

---

## ☕ Ủng hộ tác giả
Nếu bạn yêu thích dự án, đừng quên mời tác giả một ly cafe để tiếp tục duy trì và phát triển nhé:
- [Buy me a coffee ^^](https://tuyenvm.github.io/donate.html)
- [PayPal (Redbull cũng được ^^)](https://paypal.me/tuyenmai)
- Trực tiếp qua ví MoMo: [Link ủng hộ MoMo](https://tuyenvm.github.io/images/momo.png)

Cảm ơn các bạn rất nhiều!
