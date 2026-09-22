#include <iostream>
using namespace std;

int main()
{
    int m;
    cout << "Enter number of data bits: ";
    cin >> m;

    int data[50], h[100];

    cout << "Enter data bits: ";
    for (int i = 0; i < m; i++)
        cin >> data[i];

    // Find number of redundant bits
    int r = 0;

    while ((1 << r) < (m + r + 1))
        r++;

    int n = m + r;

    // Put data bits and redundant bits
    int j = 0;

    for (int i = 1; i <= n; i++)
    {
        if ((i & (i - 1)) == 0)
            h[i] = 0;
        else
            h[i] = data[j++];
    }

    // Calculate redundant bits
    for (int p = 1; p <= n; p = p * 2)
    {
        int count = 0;

        for (int i = p; i <= n; i++)
        {
            if (i & p)
                count += h[i];
        }

        h[p] = count % 2;
    }

    // Display number of redundant bits
    cout << "Number of redundant bits: " << r << endl;

    // Display redundant bits
    cout << "Redundant bits: ";

    for (int p = 1; p <= n; p = p * 2)
        cout << "R" << p << "=" << h[p] << " ";

    cout << endl;

    // Display Hamming code
    cout << "Hamming Code: ";

    for (int i = n; i >= 1; i--)
        cout << h[i];

    cout << endl;

    return 0;
}
//Enter number of data bits: 7
//Enter data bits: 1 0 1 1 0 1 0
//Number of redundant bits: 4
//Redundant bits: R1=0 R2=0 R4=0 R8=1 
//Hamming Code: 01011100100