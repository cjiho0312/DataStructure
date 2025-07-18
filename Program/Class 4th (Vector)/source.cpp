#include <iostream>

using namespace std;

template <typename T>
class Vector
{
private:

    int count;
    int capacity;

    T* container;

public:

    Vector()
    {
        count = 0;
        capacity = 0;
        container = nullptr;
    }

    void push_back(T data)
    {
        if (count == 0)
        {
            resize(1);
        }
        else
        {
            if (count >= capacity)
            {
                resize(capacity * 2);
            }

        }
        container[count++] = data;
    }

    void pop_back()
    {
        if (count <= 0)
        {
            cout << "Error : Empty Vector" << endl;
        }
        else
        {
            container[--count] = NULL;
        }
    }

    void resize(int newSize)
    {
        // 1. capacity에 새로운 size 값을 지정함.

        capacity = newSize;

        // 2. 새로운 포인터 변수 생성, 포인터가 새로운 메모리 공간을 가리키도록 함.

        T* pointer = new T[capacity];

        // 3. 새로운 메모리 공간의 값을 초기화함.

        for (int i = 0; i < capacity; i++)
        {
            pointer[i] = NULL;
        }

        // 4. 기존 배열에 있는 값을 복사해서 새로운 배열에 넣어줌.

        for (int i = 0; i < count; i++)
        {
            pointer[i] = container[i];
        }

        // 5. 기존 배열의 메모리를 해제함.

        if (container != nullptr)
        {
            delete[] container;
        }

        // 6. 기존 배열을 가리키는 포인터 변수의 값을 새로운 배열의 시작 주소로 변경.

        container = pointer;
    }


    const T& operator[](const int& index)
    {
        return container[index];
    };

    const int& size()
    {
        return count;
    }

    ~Vector()
    {
        if (container != nullptr)
        {
            delete[] container;
        }
    }
};

int main()
{
    Vector<int> vector;

    vector.push_back(10);
    vector.push_back(20);
    vector.push_back(30);
    vector.push_back(40);

    vector.pop_back();
    vector.pop_back();

    vector.push_back(5);

    for (int i = 0; i < vector.size(); i++)
    {
        cout << vector[i] << endl;
    }

    return 0;
}