#include <iostream>

using namespace std;

class String
{
private:
    int size;
    char* text;

public:
    String()
    {
        size = 0;
        text = nullptr;
    }

    void operator = (const char* word)
    {
        size = strlen(word) + 1;

        if (text == nullptr)
        {
            text = new char[size];

            for (int i = 0; i < size; i++)
            {
                text[i] = word[i];
            }
        }

        else
        {
            char* temp = new char[size];

            for (int i = 0; i < size; i++)
            {
                temp[i] = word[i];
            }

            delete[] text;

            text = temp;

        }
    }

    void append(const char* word)
    {
        int previousSize = size - 1;

        size = previousSize + strlen(word) + 1;

        char* container = new char[size];

        for (int i = 0; i < size; i++)
        {
            if (i < previousSize)
            {
                container[i] = text[i];
            }
            else
            {
                container[i] = word[i - previousSize];
            }
        }

        delete[] text;

        text = container;

    }

    unsigned long long find(const char* word)
    {
        int length = size - strlen(word);
        bool same = false;

        for (int i = 0; i < length; i++)
        {
            if (text[i] == word[0])
            {
                for (int j = 0; j < strlen(word); j++)
                {
                    if (text[i + j] != word[j])
                    {
                        same = false;
                        break;
                    }
                    same = true;
                }

                if (same == true)
                {
                    return i;
                }
            }
        }
        return 18446744073709551615;
    }

    const int& length() { return size - 1; }

    const char& operator[](const int& index)
    {
        return text[index];
    };

    ~String()
    {
        if (text != nullptr)
        {
            delete[] text;
        }
    }

};

int main()
{
    String message;

    message = "Skyrim";

    message = "Skull";

    message.append(" is Good");

    for (int i = 0; i < message.length(); i++)
    {
        cout << message[i];
    }

    cout << endl << message.find("ul");

    return 0;
}