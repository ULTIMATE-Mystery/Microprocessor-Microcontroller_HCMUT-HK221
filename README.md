# Microprocessor - Microcontroller assignment

Lớp L02 - Nhóm 007:
- Nhóm trưởng: Phạm Duy Quang - MSSV: 2011899
- Thành viên nhóm: Nguyễn Trọng Vinh - MSSV: 2015070
- Thành viên nhóm: Nguyễn Thành Quí - MSSV: 2014291

Slides trình bày: https://www.canva.com/design/DAFUIRlPmRw/t55NXGa4lA5sxmYdHFE64Q/view

Project sử dụng STM32F103RB để mô phỏng hệ thống đèn giao thông ở ngã tư với nút nhấn dành cho người đi bộ qua đường. Hệ thống đèn giao thông này có 3 mode và tổng cộng 4 nút nhấn.

<*> 4 nút nhấn hoạt động như sau:

- Button 0 - Pedestrian button (nút nhấn dành cho người đi bộ): Nút nhấn này hoạt động khi hệ thống đang ở Auto mode và Manual mode. Khi nhấn nút này, đèn của người đi bộ sẽ hiển thị ngược lại với đèn giao thông trên tuyến đường. Buzzer (còi) sẽ không kêu khi ở Manual mode. Ở Auto mode, buzzer sẽ kêu khi đèn người đi bộ là đèn xanh và khi counter (thời gian) đèn xanh của người đi bộ càng giảm thì buzzer kêu càng to. Buzzer sẽ tự động tắt ở cuối chu kỳ đèn vàng thứ 2 của tuyến đường giao thông kể từ khi được nhấn.

- Button 1 - Mode button: Nhấn nút này để chuyển mode theo tuần tự: Auto mode -> Manual mode -> Tuning mode.

- Button 2 - Switching button: Chức năng của nút nhấn này là để chuyển trạng thái sáng đèn giao thông ở 2 mode: Manual mode và Tunning mode.

- Button 3 - Tuning button: Ở Tunning mode, nhấn nút này để điều chỉnh thời gian sáng của từng đèn giao thông.


<*> 3 mode hoạt động như sau:

- Auto mode: Đèn giao thông sẽ hoạt động theo chu kỳ bình thường. Nhấn Button 1 để chuyển sang Manual mode.

- Manual mode:
  + Khi chuyển từ Auto mode sang Manual mode thì trạng thái sáng đèn giao thông vẫn giữ nguyên như khi ở Auto mode.
  + Khi Button 2 được nhấn, hệ thống đèn sẽ chuyển sang trạng thái sáng đèn giao thông tiếp theo như chu kỳ khi ở Auto mode.
  + Khi Button 2 không được nhấn sau 30s thì hệ thống sẽ quay lại Auto mode, và trạng thái sáng đèn sẽ là trạng thái đèn giao thông tiếp theo như chu kỳ.
  + Khi Button 1 được nhấn sẽ chuyển sang Tuning mode.

- Tuning mode:
  + Tuning mode sẽ dùng để điều chỉnh giá trị thời gian. Lưu ý thời gian: Đỏ1 = Xanh2 + Vàng2, Đỏ2 = Xanh1 + Vàng1 (Đỏ >= 2)
  + Lần lượt các giá trị sẽ được điều chỉnh là Đỏ1, Đỏ2, Xanh1, Xanh2, Vàng1, Vàng2.
  + Đỏ1 sẽ được chỉnh từ [2 -> 99]. Nếu Đỏ1 <= Vàng2 thì đặt lại Vàng2 = 1 và đặt lại Xanh2 = Đỏ1 - Vàng2. Tương tự như vậy với Đỏ2.
  + Xanh1 sẽ được chỉnh từ [1 -> (Đỏ2 - 1)] và đặt lại Vàng1 = Đỏ2 - Xanh1. Tương tự như vậy với Xanh2.
  + Vàng1 sẽ được chỉnh từ [1 -> (Đỏ2 - 1)] và đặt lại Xanh1 = Đỏ2 - Vàng1. Tương tự như vậy với Vàng2.
  + Khi Button 1 được nhấn sẽ chuyển về Auto mode.
