#include <iostream>
#include <string>
using namespace std;

int main()
{
    string codeword, generator;

    cout << "Enter received codeword: ";
    cin >> codeword;

    cout << "Enter generator bits: ";
    cin >> generator;

    int generatorLength = generator.length();

    // Copy received codeword for modulo-2 division
    string temp = codeword;

    // Modulo-2 division using XOR
    for (int i = 0; i <= temp.length() - generatorLength; i++)
    {
        if (temp[i] == '1')
        {
            for (int j = 0; j < generatorLength; j++)
            {
                if (temp[i + j] == generator[j])
                    temp[i + j] = '0';
                else
                    temp[i + j] = '1';
            }
        }
    }

    // Get CRC remainder
    string remainder = temp.substr(
        temp.length() - (generatorLength - 1)
    );

    // Check whether remainder contains any 1
    bool error = false;

    for (char bit : remainder)
    {
        if (bit == '1')
        {
            error = true;
            break;
        }
    }

    cout << "\n----- CRC Receiver Side -----" << endl;
    cout << "Received Codeword : " << codeword << endl;
    cout << "Generator Bits    : " << generator << endl;
    cout << "CRC Remainder     : " << remainder << endl;

    if (error)
    {
        cout << "Error Present     : YES" << endl;
        cout << "Error detected." << endl;
    }
    else
    {
        cout << "Error Present     : NO" << endl;
        cout << "No error detected." << endl;
    }

    return 0;
}

//output:
//----- CRC Receiver Side -----
//Received Codeword : 11010110111110
//Generator Bits    : 10011
//CRC Remainder     : 0000
//Error Present     : NO
//No error detected.