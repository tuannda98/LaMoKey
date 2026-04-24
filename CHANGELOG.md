# Nhật Ký Cập Nhật LaMoKey (Changelog)

Tài liệu này ghi chú lại tất cả những thay đổi, cải tiến và sửa lỗi nổi bật qua các phiên bản của dự án LaMoKey.

---

## 🛠 Nền Tảng Đang Phát Triển
**LaMoKey for Linux:** Đang trong giai đoạn phát triển (In development).

---

## 🚀 Các Phiên Bản Mới

### [1.2 RC5] - 26/08/2019
- Sửa lỗi không gõ được chữ "quởn".
- Không kiểm tra chính tả khi sử dụng các dấu ngoặc `[ ]`, `{ }`.

### [1.2 RC4] - 24/08/2019
- Cải tiến bảng gõ tắt tiện lợi hơn, bổ sung thêm tính năng Sửa từ.
- Cải thiện khả năng bỏ dấu, tối ưu hóa tốc độ xử lý nhanh hơn.
- Tự phục hồi dấu câu khi xóa ký tự (VD: chữ “tuỳa” xóa “a” sẽ tự động trả về “tùy”,… ).
- Sửa lỗi không gõ được từ “quét” khi bật chức năng tự phục hồi phím.
- Sửa lỗi hiển thị chữ `ư` và `ơ` khi sử dụng font Palatino trong phần mềm MS Word.
- Sửa lỗi bảng mã VNI: khi xóa ký tự thì không thể gõ tiếng Việt tiếp được.

### [1.2 RC3] - 16/08/2019
- Khắc phục lỗi không gõ được "dui9", "duoi96".
- Khắc phục lỗi không gõ được "tuyps".

### [1.2 RC2] - 15/08/2019
- Sửa lỗi không gõ được "d i e u 9 6".
- Sửa lỗi không gõ tắt được khi dùng chế độ tiếng Anh đối với từ bắt đầu bằng.
- Sửa lỗi tự nhảy dấu khi gõ sai văn bản.
- Bổ sung thêm thông tin phiên bản trong bảng Cài đặt/Giới thiệu.

### [1.2 RC1] - 13/08/2019
- **Chuyển chế độ thông minh:** Khi bạn đang dùng chế độ gõ Tiếng Việt trên ứng dụng A, sau đó chuyển qua ứng dụng B đang được thiết lập dùng chế độ Tiếng Anh, LaMoKey sẽ tự động chuyển qua chế độ Tiếng Anh. Khi bạn quay lại ứng dụng A, chế độ gõ tiếng Việt sẽ tự động được phục hồi. Rất cơ động.
- **Viết hoa chữ cái đầu câu:** Tự động nhận diện và viết hoa chữ cái đầu tiên của câu tiếp theo (sau dấu ngắt câu hoặc xuống dòng) giúp soạn thảo văn bản dài liền mạch hơn.
- Khôi phục phím với từ sai: hỗ trợ tự động phục hồi khi sử dụng thêm các dấu ngắt câu như dấu chấm, phẩy...
- Khắc phục và tối ưu hóa vài lỗi nhỏ khác.

### [1.1 RC] - 12/08/2019
- **Chế độ “Gửi từng phím”:** Phiên bản 1.1 mặc định dùng kỹ thuật mới gửi toàn bộ dữ liệu 1 lần (thay vì gửi nhiều lần cho từng ký tự). Kỹ thuật này giúp tăng tốc độ gõ đáng kể. Nếu ứng dụng cũ của bạn không tương thích, có thể bật chế độ "Gửi từng phím" trong cài đặt.
- Phục hồi phím thông minh đối với từ nhập sai.
- Nâng cao năng lực và độ chính xác của tính năng kiểm tra chính tả.
- Sửa lỗi bị gạch chân ở thanh địa chỉ của trình duyệt (Có thể cấu hình On/Off).
- Loại bỏ tính năng "Cho phép bỏ dấu tự do" vì dễ gây sai sót.
- Cải tiến tính năng Gõ tắt (Macro): Cho phép bật/tắt dễ dàng, soạn từ gõ tắt, hỗ trợ nhập ký tự bất kỳ với bảng mã bất kỳ. (*Lưu ý: Bảng soạn từ gõ tắt yêu cầu nhập liệu ở bảng mã Unicode dựng sẵn*).
- Cho phép áp dụng lệnh gõ tắt ngay cả khi ở trong chế độ gõ tiếng Anh (On/Off).
- Tương thích và sửa lỗi không nhận diện trên một số phần mềm đặc thù.

### [1.0.20] - 06/08/2019
- Sửa lỗi phím tắt chuyển chế độ gõ (Phím tắt của ứng dụng khác vẫn sẽ hoạt động bình thường nếu xảy ra trùng lặp cục bộ).
- Cho phép gõ chữ “Đ” ngay sau khi nhập phụ âm.
- Ẩn hiển thị icon trên thanh Dock trong mục Recent Apps của macOS.
- Khắc phục lỗi gõ “oăc” bị biến thành “ooạc” ở kiểu gõ VNI.
- Cải tiến vài lỗi kỹ thuật nhỏ khác.

### [1.0.19] - 04/08/2019
- Khắc phục lỗi không gõ được chữ “gì” khi sử dụng thiết lập bỏ dấu kiểu cũ.
- Sửa lỗi không gõ được Unicode tổ hợp (Compound) trên ứng dụng Stickies của macOS.
- Khắc phục lỗi gõ các tổ hợp âm "oong", "ooc".

### [1.0.18] - 01/08/2019
- Không sử dụng luật w -> ư trong kiểu gõ Simple Telex để tránh nhầm lẫn.
- Cung cấp tùy chọn Bật/Tắt âm thanh (beep) khi chuyển đổi chế độ gõ.
- Thêm tổ hợp phím chuyển chế độ (Shift). Có thể sử dụng `Ctrl + Shift` hoặc `Command + Shift`.
- Bổ sung khả năng hỗ trợ cho các bản macOS cũ hơn.
- Sửa một số lỗi hoạt động chung.

### [1.0.17] - 31/07/2019
- Bổ sung thêm chế độ gõ **Simple Telex**.
- Cung cấp tùy chọn đổi icon Trắng/Đen (Gray icon) trên Menu Bar phù hợp giao diện của hệ thống.
- Cải thiện phản hồi xử lý phím Space và phím Backspace. Lỡ bấm Space, khi xoá dấu cách đi vẫn có thể tiếp tục bỏ dấu cho từ.
- Tùy chọn luật bỏ dấu kiểu Cũ/Mới (òa, úy hay oà, uý) - Modern orthography.
- Tùy chọn tùy biến hoàn toàn phím tắt chuyển đổi chế độ gõ.
- Tích hợp tính năng Gõ Nhanh / Quick Telex (`cc=ch`, `gg=gi`, `kk=kh`, `nn=ng`, `qq=qu`, `pp=ph`, `tt=th`).
- Hỗ trợ tốt cho trình soạn thảo TextWrangler.

### [1.0.14] - 09/04/2019
- Bổ sung xử lý cho trường hợp gõ chữ "uýt".
- Cải thiện đáng kể khả năng gõ tiếng Anh trong lúc bật chế độ gõ tiếng Việt.

### [1.0.11] - 27/02/2019
- Thêm trường hợp ngoại lệ cho từ "chú thòong", "gòong".

### [1.0.10] - 26/02/2019
- Sửa lỗi không thể gõ trường hợp "duocd".

### [1.0.9] - 22/02/2019
- Sửa lỗi xuất hiện từ sai khi thực hiện đổi ngôn ngữ/chế độ gõ mà không nhấn phím Space để kết thúc từ.

### [1.0.8] - 19/02/2019
- Thay đổi phím tắt chuyển ngôn ngữ mặc định: Chuyển từ `Control + Command + Space` thành `Control + Z` để tối ưu trải nghiệm.

### [1.0.7] - 15/02/2019
- Khắc phục lỗi cho trường hợp "duongd".
- Khắc phục lỗi gõ liên quan đến phụ âm cuối "t".

### [1.0.6] - 15/02/2019
- Khắc phục lỗi cho trường hợp "quatw".

### [1.0.5] - 13/02/2019
- Nâng cấp và cải tiến thuật toán soát lỗi chính tả.
- Sửa lỗi độ phân giải icon, tương thích hoàn toàn cho các màn hình không phải Retina (màn hình non-retina / 1x).

### [1.0.3] - 11/02/2019
- Khắc phục các vấn đề liên quan đến tính năng Auto Correct trên trình duyệt Google Chrome.

### [1.0.0] - 11/02/2019
- 🎉 Phát hành lần đầu (First release).