#include <iostream>
#include <string>
using namespace std;

int main()
{
    string code;
    cout << "Enter received Hamming code: ";
    cin >> code;

    string receivedCode = code;   // Store original received codeword

    int n = code.length();

    // Find number of parity bits
    int r = 0;
    while ((1 << r) < (n + 1))
    {
        r++;
    }

    int errorPosition = 0;

    // Parity checking
    for (int i = 0; i < r; i++)
    {
        int parityPosition = (1 << i);
        int count = 0;

        for (int j = 1; j <= n; j++)
        {
            if (j & parityPosition)
            {
                if (code[n - j] == '1')
                    count++;
            }
        }

        if (count % 2 != 0)
            errorPosition += parityPosition;
    }

    cout << "\nReceived codeword: " << receivedCode << endl;

    if (errorPosition == 0)
    {
        cout << "No error detected." << endl;
    }
    else
    {
        cout << "Error at position: " << errorPosition << endl;

        // Correct the error
        int index = n - errorPosition;

        if (code[index] == '0')
            code[index] = '1';
        else
            code[index] = '0';

        cout << "Corrected codeword: " << code << endl;
    }

    // Extract original data bits
    cout << "Original data bits: ";

    for (int j = 1; j <= n; j++)
    {
        // Skip parity positions: 1, 2, 4, 8, ...
        if ((j & (j - 1)) != 0)
        {
            cout << code[n - j];
        }
    }

    cout << endl;

    return 0;
}
//output:
//Enter received Hamming code: 01011100100

//Received codeword: 01011100100
//No error detected.
//Original data bits: 1011010