#include <iostream>
#include <string>
using namespace std;

int main()
{
    string input;
    int count = 0;

    cout << "original frame: ";
    cin >> input;

    cout << "Stuffed frame: ";

    for (char c : input)
    {
        cout << c;

        if (c == '1')
        {
            count++;

            if (count == 5)
            {
                cout << '0';
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