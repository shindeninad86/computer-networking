#include <iostream>
#include <string>
using namespace std;

int main()
{
    string input;
    int count = 0;

    cout << "Enter stuffed frame: ";
    cin >> input;

    cout << "Destuffed frame: ";

    for (int i = 0; i < input.length(); i++)
    {
        char c = input[i];

        cout << c;

        if (c == '1')
        {
            count++;

            if (count == 5)
            {
                i++;          
                count = 0;
            }
        }
        else
        {
            count = 0;
        }
    }

    return 0;
}