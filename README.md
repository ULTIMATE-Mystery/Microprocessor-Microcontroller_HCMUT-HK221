# Microprocessor - Microcontroller assignment

Hệ thống đèn giao thông ở ngã tư với nút nhấn dành cho người đi bộ qua đường có 3 mode và tổng cộng 4 nút nhấn.

*) 4 nút nhấn hoạt động như sau:

- Button0 - Pedestrian button (nút nhấn dành cho người đi bộ): Khi nhấn nút này, đèn của người đi bộ sẽ hiển thị theo đèn trên tuyến đường. Buzzer (loa) sẽ kêu khi đèn người đi đường là đèn xanh và khi counter (thời gian) của đèn xanh càng giảm thì buzzer kêu càng to. Nút nhấn này hoạt động khi hệ thống đang ở Auto mode và Manual mode. Chức năng này sẽ tự động tắt ở cuối chu kì đèn vàng thứ 2 tính từ khi được nhấn.

- Button1 - Mode button: Nhấn nút này để chuyển mode theo tuần tự: Auto mode -> Manual mode -> Tuning mode.

- Button2 - Switching button: Chức năng của nút nhấn này là để chuyển trạng thái sáng đèn giao thông ở 2 mode: Manual mode và Tunning mode.

- Button3 - Tuning button: Ở Tunning mode, nhấn nút này để điều chỉnh thời gian sáng của từng đèn giao thông.


*) 3 mode hoạt động như sau:

- Auto mode:
  + Đèn sẽ hoạt động bình thường theo chu kỳ (Đỏ-Xanh -> Đỏ-Vàng -> Xanh-Đỏ -> Vàng-Đỏ).
  + Khi Button1 được nhấn sẽ chuyển sang Manual mode.

- Manual mode:
  + Khi chuyển từ auto mode sang manual mode thì trạng thái đèn vẫn giữ nguyên như khi ở auto mode.
  + Khi Button2 được nhấn hệ thống đèn sẽ chuyển sang trạng thái tiếp theo như khi ở auto mode.
  + Khi Button2 không được nhấn sau 30s thì hệ thống sẽ quay lại auto mode, và trạng thái của đèn sẽ là trạng thái tiếp theo.
  + Khi Button1 được nhấn sẽ chuyển sang tuning mode.

- Tuning mode:
  + Tuning mode sẽ dùng để set giá trị duration. Lưu ý duration: Đỏ1 = Xanh2 + Vàng2, Đỏ2 = Xanh1 + Vàng1 (Đỏ >= 2)
  + Lần lượt các giá trị sẽ được điều chỉnh là Đỏ1, Đỏ2, Xanh1, Xanh2, Vàng1, Vàng2.
  + Đỏ1 sẽ được chỉnh từ [2 -> 99]. Nếu Đỏ1 <= Vàng2 thì đặt lại Vàng2 = 1 và đặt lại Xanh2 = Đỏ1 - Vàng2. Tương tự như vậy với Đỏ2.
  + Xanh1 sẽ được chỉnh từ [1 -> (Đỏ2 - 1)] và đặt lại Vàng1 = Đỏ2 - Xanh1. Tương tự như vậy với Xanh2.
  + Vàng1 sẽ được chỉnh từ [1 -> (Đỏ2 - 1)] và đặt lại Xanh1 = Đỏ2 - Vàng1. Tương tự như vậy với Vàng2.
  + Khi Button1 được nhấn sẽ chuyển sang Auto mode.