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

    void operator = (const char * word)
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

    const int& length() { return size; }

    const char& operator[](const int& index)
    {
        return text[index];
    };

    ~String()
    {
        if (text != nullptr)
        {
            delete [] text;
        }
    }

};

int main()
{
    String m;

    m = "Skyrim";

    m = "Skull";

    for (int i = 0; i < m.length(); i++)
    {
        cout << m[i];
    }

    return 0;
}