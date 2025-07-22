#include <iostream>

#define SIZE 5

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
        front = 0;
        rear = 0;

        for (int i = 0; i < SIZE; i++)
        {
            container[i] = NULL;
        }
    }

    void push(T data)
    {
        if (rear >= SIZE)
        {
            cout << "Queue overflow" << endl;
        }
        else
        {
            container[rear++] = data;
        }
    }

    void pop()
    {
        if (empty())
        {
            cout << "Queue Empty" << endl;
        }
        else
        {
            container[front++] = NULL;
        }
    }

    const T& Front()
    {
        return front;
    }

    const int& size()
    {
        return rear - front;
    }

    void showQueue()
    {
        for (int i = front; i < rear; i++)
        {
            cout << container[i] << " ";
        }
        cout << endl;
    }

    bool empty()
    {
        return (front == rear);
    }
};

int main()
{
    Queue<int> queue;

    queue.push(10);
    queue.push(20);
    queue.push(30);
    queue.push(40);

    queue.pop();

    queue.showQueue();

    cout << "Front : " << queue.Front() << endl;
    cout << "Size : " << queue.size() << endl;

    return 0;
}