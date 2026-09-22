#include <iostream>
#include <string>
using namespace std;

int main()
{
    string data, generator;

    cout << "Enter data bits: ";
    cin >> data;

    cout << "Enter generator bits: ";
    cin >> generator;

    int generatorLength = generator.length();

    // Append zeros
    string zeroAppended = data;

    for (int i = 0; i < generatorLength - 1; i++)
    {
        zeroAppended += '0';
    }

    // Copy for modulo-2 division
    string temp = zeroAppended;

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

    // Get redundancy bits (remainder)
    string remainder = temp.substr(
        temp.length() - (generatorLength - 1)
    );

    // Generate codeword
    string codeword = data + remainder;

    cout << "\n----- CRC Sender Side -----" << endl;
    cout << "Data bits        : " << data << endl;
    cout << "Generator bits   : " << generator << endl;
    cout << "Zero appended    : " << zeroAppended << endl;
    cout << "Redundancy bits  : " << remainder << endl;
    cout << "Codeword         : " << codeword << endl;

    return 0;
}
//output:
//----- CRC Sender Side -----
//Data bits        : 1101011011
//Generator bits   : 10011
//Zero appended    : 11010110110000
//Redundancy bits  : 1110
//Codeword         : 11010110111110