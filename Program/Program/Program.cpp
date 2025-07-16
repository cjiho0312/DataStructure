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
    };

    Node* head;

public:

    List()
    {
        size = 0;
        head = nullptr;
    }

    void push_back(T data)
    {
        Node* newNode = new Node;

        newNode->data = data;

        if (head == nullptr)
        {
            head = newNode;
            newNode->next = head;
        }
        else
        {
            newNode->next = head->next;
            
            head->next = newNode;

            head = newNode;
        }

        size++;
    }

    void push_front(T data)
    {
        Node* newNode = new Node;

        newNode->data = data;

        if (head == nullptr)
        {
            head = newNode;
            newNode->next = head;
        }
        else
        {
            newNode->next = head->next;

            head->next = newNode;
        }

        size++;
    }

    void pop_front()
    {
        Node* deleteNode = head;

        if (head == nullptr)
        {
            cout << "Error" << endl;
        }
        else
        {
            if (size == 1)
            {
                delete deleteNode;

                head = nullptr;
            }
            else
            {
                deleteNode = head->next;

                head->next = deleteNode->next;
                
                delete deleteNode;
            }

            size--;
        }

    }

    void showList()
    {
        Node* currentNode = head;
        int count = 0;

        cout << "List : ";

        for (int i = 0; i < size; i++)
        {
            cout << "> " << currentNode->data << " -";

            currentNode = currentNode->next;
            count++;
        }

        cout << "\n      |";
        for (int i = 0; i < count; i++)
        {
            cout << "______";
        }
        cout << "|" << endl;


    }


};

int main()
{
    List <int> list;

    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    list.push_back(40);

    list.push_front(5);
    list.push_front(3);
    list.push_front(1);

    list.pop_front();

    list.showList();

    return 0;
}