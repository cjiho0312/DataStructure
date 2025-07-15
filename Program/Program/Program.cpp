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
        head = NULL;
        tail = NULL;
    }

    void push_front(T data)
    {
        Node* newNode = new Node;
    
        newNode->data = data;
        newNode->previous = nullptr;
        newNode->next = nullptr;
    
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            head->previous = newNode;
            newNode->next = head;
            head = newNode;
        }
        size++;
    }

    void pop_front()
    {
        if (size == 0)
        {
            cout << "Error : Empty list" << endl;
            return;
        }

        Node* deleteNode = head;

        if (size == 1)
        {
            head = nullptr;
            tail = nullptr;
        }
        else if (size > 1)
        {
            deleteNode->next->previous = nullptr;
            
            head = head->next;
        }
        delete deleteNode;
        size--;
    }

    void push_back(T data)
    {
        Node* newNode = new Node;

        newNode->data = data;
        newNode->previous = nullptr;
        newNode->next = nullptr;

        if (tail == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->previous = tail;
            tail = newNode;
        }
        size++;
    }

    void pop_back()
    {
        if (size == 0)
        {
            cout << "Error : Empty list";
            return;
        }

        Node* deleteNode = tail;

        if (size == 1)
        {
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            deleteNode->previous->next = nullptr;
            tail = tail->previous;
        }
        delete deleteNode;
        size--;
    }

    bool empty()
    {
        return (head == nullptr);
    }

    void Listdata()
    {
        Node* currentNode = head;

        cout << "List : ";

        while (currentNode != nullptr)
        {
            cout << currentNode->data << " ";
            currentNode = currentNode->next;
        }

        cout << endl;
    }

    void Search(T data)
    {
        Node* currentNode = head;
        int count = 0;

        while (currentNode != nullptr)
        {
            if (currentNode->data == data)
            {
                count++;
            }

            currentNode = currentNode->next;

        }

        cout << "Data '" << data << "' count : " << count << endl;
    }

    ~List() 
    {
        while (head != nullptr)
        {
            pop_front();
        }

        cout << "Release List";
    }
};

int main()
{
    List<int> list;
    
    list.push_front(10);
    list.push_front(20);
    list.push_front(30);

    list.pop_front();

    list.push_back(20);
    list.push_back(40);

    list.pop_back();

    list.Search(20);
    list.Listdata();

    cout << "Is this list empty? " << list.empty() << endl;

    return 0;
}