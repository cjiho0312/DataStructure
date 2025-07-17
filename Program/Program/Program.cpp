#include <iostream>

using namespace std;

template <typename T>
class Vector
{
private:

    int size;
    int capacity;

    T* container;
    
public:

    Vector()
    {
        size = 0;
        capacity = 0;
        container = nullptr;
    }

    void push_back(T data)
    {
        if (size == 0)
        {
            resize(1);
            container[0] = data;
        }
        else
        {
            if (size == capacity)
            {
                resize(size + 2);
            }

            int findSeat;

            
        
        }



        size++;
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

        for (int i = 0; i < size; i++)
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

    void showArray()
    {
        cout << "{ ";
        for (int i = 0; i < size; i++)
        {
            cout << container[i] << " ";
        }
        cout << "}";
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

    vector.showArray();

    return 0;
}