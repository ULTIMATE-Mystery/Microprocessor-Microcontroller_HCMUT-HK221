# Microprocessor - Microcontroller assignment

- Auto mode:
  + Đèn sẽ hoạt động bình thường theo chu kì (Đỏ-Xanh -> Đỏ-Vàng -> Xanh-Đỏ -> Vàng-Đỏ).
  + Khi Button1 được nhấn sẽ chuyển sang Manual mode.

- Manual mode:
  + Khi chuyển từ auto mode sang manual mode thì trạng thái đèn vẫn giữ nguyên như khi ở auto mode.
  + Khi Button2 được nhấn hệ thống đèn sẽ chuyển sang trạng thái tiếp theo như khi ở auto mode.
  + Khi Button2 không được nhấn sau 60s thì hệ thống sẽ quay lại auto mode, và trạng thái của đèn sẽ là trạng thái tiếp theo.
  + Khi Button1 được nhấn sẽ chuyển sang tuning mode.

- Tuning mode:
  + Tuning mode sẽ dùng để set giá trị duration. Lưu ý duration: đỏ1 = xanh2 + vàng2, đỏ2 = xanh1 + vàng1 (đỏ >= 2)
  + Lần lượt các giá trị sẽ được điều chỉnh là đỏ1, đỏ2, xanh1, xanh2, vàng1, vàng2.
  + Đỏ1 sẽ được chỉnh từ 2->99. Nếu đỏ1 <= vàng2 thì đặt lại vàng2 = 1. Đặt lại xanh2 = đỏ1 - vàng2. Tương tự với đỏ2.
  + Xanh1 sẽ được chỉnh từ 1->đỏ2. Đặt lại vàng2 = đỏ1 - xanh2. Tương tự với Xanh2.
  + Vàng1 sẽ được chỉnh từ 1->đỏ2. Đặt lại xanh2 = đỏ1 - vàng2. Tương tự với Vàng2.
  + Khi Button1 được nhấn sẽ chuyển sang auto mode.

Pedestrian button: khi nhấn nút này đèn của người đi bộ sẽ hiển thị theo đèn trên tuyến đường. Buzzer sẽ kêu khi đèn người đi đường là đèn xanh và khi counter
của đèn xanh càng giảm thì buzzer kêu càng to. Nút nhấn này chỉ hoạt động khi hệ thống đang ở auto mode hoặc manual mode. Chức năng này sẽ tự động tắt ở cuối
chu kì đèn vàng thứ 2 tính từ khi được nhấn.
