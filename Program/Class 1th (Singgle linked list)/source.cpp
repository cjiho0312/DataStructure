#include <iostream>

using namespace std;

template <typename T>
class List
{
private:
    int listsize;

    struct Node
    {
        T data;
        Node* next;
    };

    Node* head;

public:
    List()
    {
        listsize = 0;
        head = nullptr;
    }

    void push_front(T data)
    {
        Node* newnode = new Node;
        newnode->data = data;

        if (head == nullptr)
        {
            head = newnode;
            newnode->next = nullptr;
        }
        else
        {
            newnode->next = head;
            head = newnode;
        }

        listsize++;
    }


    void push_back(T data)
    {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = nullptr;

        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node* currentNode = head;

            while (currentNode->next != nullptr)
            {
                currentNode = currentNode->next;
            }

            currentNode->next = newNode;
        }


        listsize++;

    }

    void pop_front()
    {
        if (head == nullptr)
        {
            cout << "삭제할 데이터가 없습니다." << endl;
        }
        else
        {
            Node* deleteNode = head;

            head = deleteNode->next;

            delete deleteNode;

            listsize--;
        }
    }

    void pop_back()
    {
        if (head == nullptr)
        {
            cout << "삭제할 데이터가 없습니다." << endl;
        }
        else
        {
            Node* deleteNode = head;
            Node* previousNode = nullptr;

            if (head->next == nullptr)
            {
                delete head;
                head = nullptr;
            }
            else
            {
                while (deleteNode->next != nullptr)
                {
                    previousNode = deleteNode;
                    deleteNode = deleteNode->next;
                }

                previousNode->next = deleteNode->next;
                delete deleteNode;
            }

            listsize--;
        }
    }

    void Remove(T data)
    {
        if (head == nullptr)
        {
            return;
        }
        else
        {
            Node* deleteNode = head;
            Node* previousNode = head;

            while (deleteNode != nullptr)
            {
                if (deleteNode->data == data)
                {
                    if (deleteNode == head)
                    {
                        head = deleteNode->next;
                    }
                    else
                    {
                        previousNode->next = deleteNode->next;
                    }

                    delete deleteNode;

                    listsize--;

                    deleteNode = head;
                }

                previousNode = deleteNode;

                deleteNode = deleteNode->next;
            }
        }
    }

    bool empty()
    {
        // if (listsize == 0)
        // {
        //     return true;
        // }
        // else if (listsize != 0)
        // {
        //     return false;
        // }

        return (head == nullptr);
    }

    ~List()
    {
        while (head != nullptr)
        {
            pop_front();
        }

        if (listsize == 0)
        {
            cout << "Deleted all data" << endl;
        }
    }
};

int main()
{
    List<int> list;

    cout << list.empty() << endl;

    list.push_front(10);
    list.push_front(20);
    list.push_front(30);

    list.push_back(5);
    list.push_back(15);

    list.Remove(20);

    cout << list.empty() << endl;


    return 0;
}