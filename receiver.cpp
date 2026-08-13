#include <iostream>
using namespace std;

int main()
{
    char input[200], output[200];
    int i, j = 0;
    int count = 0;

    cout << "Enter Stuffed Bit Stream: ";
    cin >> input;

    for (i = 0; input[i] != '\0'; i++)
    {
        output[j] = input[i];
        j++;

        if (input[i] == '1')
        {
            count++;

            if (count == 5)
            {
                i++;       // Skip the stuffed '0'
                count = 0;
            }
        }
        else
        {
            count = 0;
        }
    }

    output[j] = '\0';

    cout << "Received Stuffed Bit Stream : " << input << endl;
    cout << "Original Bit Stream         : " << output << endl;

    return 0;
}