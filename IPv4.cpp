#include <iostream>
#include <string>
using namespace std;
int main()
{
    string ip;
    cout << "Enter IPv4 address: ";
    getline(cin, ip);

    string octet[4];    
    int count = 0;
    string temp = "";    

    
    for (int i = 0; i <= ip.length(); i++)  
    {
        if (ip[i] == '.' || i == ip.length())     
        {
            if (temp == "")   
            {
                cout << "Invalid IPv4 Address" << endl;
                return 0;
            }
            octet[count] = temp;   
            count++;               
            temp = "";              

            if (count > 4)              
            {
                cout << "Invalid IPv4 Address" << endl;
                return 0;
            }
        }
        else
        {
            temp = temp + ip[i];   
        }
    }

    
    if (count != 4)             
    {
        cout << "Invalid IPv4 Address" << endl;
        return 0;
    }

    int value[4];
    for (int i = 0; i < 4; i++)
    {
        
        for (int j = 0; j < octet[i].length(); j++)     
        {
            if (octet[i][j] < '0' || octet[i][j] > '9')   
            {
                cout << "Invalid IPv4 Address" << endl;
                return 0;
            }
        }

        if (octet[i].length() > 1 && octet[i][0] == '0')  
        {
            cout << "Invalid IPv4 Address" << endl;
            return 0;
        }

        value[i] = stoi(octet[i]);    
        if (value[i] < 0 || value[i] > 255)   
        {
            cout << "Invalid IPv4 Address" << endl;
            return 0;
        }
    }

    cout << "\nValid IPv4 Address" << endl;
    int firstByte = value[0];

    cout << "First Byte: " << octet[0] << endl;
    cout << "First Byte as Integer: " << firstByte << endl;

    char ipClass;
    if (firstByte >= 1 && firstByte <= 127)
    {
        ipClass = 'A';
    }
    else if (firstByte >= 128 && firstByte <= 191)
    {
        ipClass = 'B';
    }
    else if (firstByte >= 192 && firstByte <= 223)
    {
        ipClass = 'C';
    }
    else if (firstByte >= 224 && firstByte <= 239)
    {
        ipClass = 'D';
    }
    else
    {
        ipClass = 'E';
    }

    cout << "Class: " << ipClass << endl;
    if (ipClass == 'A')
    {
        cout << "Net ID: "
             << value[0] << endl;

        cout << "Host ID: "
             << value[1] << "."
             << value[2] << "."
             << value[3] << endl;

        cout << "Network Address: "
             << value[0] << ".0.0.0" << endl;
    }
    else if (ipClass == 'B')
    {
        cout << "Net ID: "
             << value[0] << "."
             << value[1] << endl;

        cout << "Host ID: "
             << value[2] << "."
             << value[3] << endl;

        cout << "Network Address: "
             << value[0] << "."
             << value[1] << ".0.0" << endl;
    }
    else if (ipClass == 'C')
    {
        cout << "Net ID: "
             << value[0] << "."
             << value[1] << "."
             << value[2] << endl;

        cout << "Host ID: "
             << value[3] << endl;

        cout << "Network Address: "
             << value[0] << "."
             << value[1] << "."
             << value[2] << ".0" << endl;
    }
    else
    {
        cout << "Net ID: Not applicable" << endl;
        cout << "Host ID: Not applicable" << endl;
        cout << "Network Address: Not applicable" << endl;
    }

    return 0;
}

/*Enter IPv4 address: 126.14.15.255

Valid IPv4 Address
First Byte: 126
First Byte as Integer: 126
Class: A
Net ID: 126
Host ID: 14.15.255
Network Address: 126.0.0.0*/