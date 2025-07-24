# 🚦 ESP32 LED State Machine (FSM)

Đây là ứng dụng mẫu sử dụng mô hình **Finite State Machine (FSM)** để điều khiển LED nhấp nháy trên board **ESP32 DevKit** (GPIO 2). Ứng dụng được thiết kế với kiến trúc phân lớp hướng đối tượng, giúp dễ mở rộng và kiểm thử.

---

## 🔁 Mô hình State Machine

Ứng dụng LED Blink này sử dụng FSM gồm 4 trạng thái tuần hoàn như sau:

| State | Hành động               | Điều kiện chuyển trạng thái      | Trạng thái kế tiếp |
|-------|--------------------------|----------------------------------|---------------------|
| 1     | Nháy 1 lần (Blink 1)     | `n >= 5`                         | Chuyển sang state 2 |
| 2     | Nháy 2 lần (Blink 2)     | `n >= 20`                        | Chuyển sang state 3 |
| 3     | Nháy 3 lần (Blink 3)     | `n >= 25`                        | Chuyển sang state 4 |
| 4     | Nháy 4 lần (Blink 4)     | `n >= 30` → reset `n = 0`        | Quay về state 1     |

Biến `n` là một bộ đếm vòng lặp, tăng sau mỗi lần thực thi
(n = 0 khởi đầu)
---

## 📈 Sơ đồ trạng thái

![FSM Diagram](https://github.com/user-attachments/assets/60552091-56c1-4bc3-b2d2-4ea2330b3fec)

---


