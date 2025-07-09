#include <iostream>

using namespace std;

template <typename T>
class List
{
private:
    int size;
    
    struct Node
    {
        T data;
        Node* next;
        Node* previous;
    };

    Node* head;
    Node* tail;

public:
    List()
    {
        size = 0;
        head = nullptr;
        tail = nullptr;
    }
    ~List();
};

int main()
{

    return 0;
}