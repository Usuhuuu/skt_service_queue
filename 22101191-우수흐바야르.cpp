#include <iostream>
#include <string>

#define MAX_QUEUE_SIZE 10

class CircularQueue
{
private:
    int front, rear, count;
    int queue[MAX_QUEUE_SIZE];     // Stores the person IDs
    int waitTimes[MAX_QUEUE_SIZE]; // Stores the wait times for each person

public:
    CircularQueue() : front(0), rear(0), count(0) {}

    bool isFull() { return count == MAX_QUEUE_SIZE; }
    bool isEmpty() { return count == 0; }

    bool enqueue(int personId, int waitTime)
    {
        if (isFull())
            return false;
        queue[rear] = personId;
        waitTimes[rear] = waitTime;
        rear = (rear + 1) % MAX_QUEUE_SIZE;
        count++;
        return true;
    }

    bool dequeue(int &personId)
    {
        if (isEmpty())
            return false;
        personId = queue[front];
        front = (front + 1) % MAX_QUEUE_SIZE;
        count--;
        return true;
    }

    int size() { return count; }

    int getWaitTimeAt(int index)
    {
        if (index < 0 || index >= count)
            return -1;
        return waitTimes[(front + index) % MAX_QUEUE_SIZE];
    }
};

// Return time to add based on selected option
int getTimeByOption(int option)
{
    switch (option)
    {
    case 1:
        return 3; // 유심 변경
    case 2:
        return 2; // 번호 이동
    case 3:
        return 1; // 기타
    default:
        return 0;
    }
}

int main()
{
    CircularQueue queue;
    int personId = 1;
    int accumulatedTime = 0;

    while (true)
    {
        std::cout << "\n현재 대기 인원: " << queue.size();
        std::cout << "\n상담을 선택하세요:\n";
        std::cout << "1: 유심 변경\n2: 번호 이동\n3: 기타\n0: 종료\n입력: ";

        int option;
        std::cin >> option;

        if (option == 0)
            break;

        int timeToAdd = getTimeByOption(option);
        if (timeToAdd == 0)
        {
            std::cout << "잘못된 선택입니다.\n";
            continue;
        }

        int personWaitTime = accumulatedTime + timeToAdd;

        if (queue.enqueue(personId, personWaitTime))
        {
            accumulatedTime = personWaitTime; // Update total wait
            std::cout << "고객 #" << personId << " 대기열에 추가됨. 예상 대기 시간: "
                      << personWaitTime << " 분.\n";
            personId++;
        }
        else
        {
            std::cout << "대기열이 가득 찼습니다. 나중에 다시 시도하세요.\n";
        }
    }

    std::cout << "\n프로그램 종료.\n";
    return 0;
}
