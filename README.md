# 💡 C++ Circular Queue with 상담 대기 시간

This program simulates a consultation wait system using a circular queue. Each person’s estimated wait time depends on the option they choose and is added cumulatively.

---

## ✅ Features

- Circular queue of up to **10 people**
- Different time added per 상담 option:
  - `1: 유심 변경` → +3 minutes
  - `2: 번호 이동` → +2 minutes
  - `3: 기타` → +1 minute
- Total wait time is accumulated and displayed for each new person
- Option `0` exits the program

---

## 🧠 Code Explanation

### `CircularQueue` Class


The `CircularQueue` class implements a fixed-size circular queue to manage the consultation waitlist. It uses two arrays:
- `queue[]` to store the person IDs.
- `waitTimes[]` to store the wait times for each person in the queue.

Key Methods:
- `isFull()`: Checks if the queue has reached its maximum capacity (10 people).
- `isEmpty()`: Checks if the queue is empty.
- `enqueue(personId, waitTime)`: Adds a new person to the queue along with their calculated wait time.
- `size()`: Returns the current number of people in the queue.

### `getTimeByOption` Function

This function determines the wait time based on the chosen 상담 option:
- `1: 유심 변경` → Adds **+3 minutes** to the accumulated wait time.
- `2: 번호 이동` → Adds **+2 minutes** to the accumulated wait time.
- `3: 기타` → Adds **+1 minute** to the accumulated wait time.
- Invalid options return **+0 minutes**.

### Main Program Logic

1. **Initialization**:
   - The program initializes `accumulatedTime` to `0` and `personId` to `1`.
2. **Loop**:
   - The program enters a loop where it displays the current number of people in the queue.
   - It prompts the user for an option (1, 2, 3, or 0 to exit).
   - Based on the chosen option, the corresponding time is added to the `accumulatedTime`.
   - The program attempts to add the person to the queue with the updated wait time.
   - If successful, it displays the person’s ID and estimated wait time. If the queue is full, it displays an error message.
3. **Exit**:
   - If the user enters `0`, the program exits.

---

## 🧮 Wait Time Calculation

Instead of multiplying the current queue size by a fixed multiplier, the program simply adds time based on the selected option:
- Every time a new person joins the queue, their wait time is calculated by adding the time corresponding to their chosen option to the `accumulatedTime`.
- This cumulative method reflects how the total wait time increases as more people join the queue.

---

## 📝 Conclusion

This program provides a simple simulation of a queue system where each new person’s wait time depends on their choice of 상담 option. It uses a circular queue to efficiently manage up to 10 people and ensures that the wait times are updated dynamically as more people join the queue.

---
<img width="546" alt="Screenshot 2025-05-11 at 10 27 17 PM" src="https://github.com/user-attachments/assets/3b15aca1-21bd-4542-87ba-ae2797d0f6ec" />


