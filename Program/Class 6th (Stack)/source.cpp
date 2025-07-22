#include <iostream>

using namespace std;

#define SIZE 5


template <typename T>
class Stack
{
private:
    int count;
    int highset;
    T container[SIZE];

public:
    Stack()
    {
        count = 0;
        highset = -1;

        for (int i = 0; i < SIZE; i++)
        {
            container[i] = NULL;
        }
    }

    void push(T data)
    {
        if (count >= SIZE)
        {
            cout << "Stack overflow" << endl;
        }
        else
        {
            container[++highset] = data;
            count++;
        }
    }

    void pop()
    {
        if (count <= 0)
        {
            cout << "Stack Empty" << endl;
        }
        else
        {
            --highset;
            --count;
        }
    }

    const int& size()
    {
        return count;
    }

    const T& top()
    {
        return container[highset];
    }

    bool empty()
    {
        return (count == 0);
    }

    void showStack()
    {
        for (int i = 0; i < count; i++)
        {
            cout << "[" << i << "] : " << container[i] << endl;
        }
        cout << endl << endl;
    }
};

int main()
{
    Stack<int> stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    stack.push(50);

    stack.pop();
    stack.pop();

    stack.showStack();

    cout << "Empty : " << stack.empty() << endl;
    cout << "Size : " << stack.size() << endl;
    cout << "Top data : " << stack.top() << endl;

    return 0;
}