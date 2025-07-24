#include <iostream>

#define SIZE 4

using namespace std;

template <typename T>
class Queue
{
private:
    int front;
    int rear;
    T container[SIZE];

public:
    Queue()
    {
        front = SIZE - 1;
        rear = SIZE - 1;

        for (int i = 0; i < SIZE; i++)
        {
            container[i] = NULL;
        }
    }

    void push(T data) // 수정요함
    {
        int tempFront = SIZE - 1;

        if (rear > 0)
        {
            tempFront = front;
        }

        if (rear + 1 == tempFront)
        {
            cout << "Queue overflow" << endl;
        }
        else
        {
            if (++rear >= temp)
            {
                rear = -1;
            }

            container[++rear] = data;
        }

    }

    void showQueue()
    {
        for (int i = 0; i < SIZE; i++)
        {
            cout << container[i] << " ";
        }
    }

};

int main()
{
    Queue <int> queue;

    queue.push(10);
    queue.push(20);
    queue.push(30);
    queue.push(40);

    queue.showQueue();

    return 0;
}