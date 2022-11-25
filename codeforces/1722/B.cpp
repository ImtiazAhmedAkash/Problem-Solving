// Colourblindness

#include <bits/stdc++.h>
using namespace std;

/*
 * Vasya can't distinguish between B and G. So, they are the same.
 * 
 * Take two strings a and b.
 * If a[i] is 'R' and b[i] != 'R' or vice versa, 
 * Vasya will be able to identify the strings as of different color.
 */

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int test;
    cin >> test;
    while (test--)
    {
        int length;
        cin >> length;
        string a, b;
        cin >> a >> b;

        for (int i = 0; i < length; i++)
        {
            if ((a[i] == 'R' && b[i] != 'R') || (b[i] == 'R' && a[i] != 'R'))
            {
                cout << "NO" << "\n";
                break;
            }
            if (i == length - 1)
                cout << "YES" << "\n";
        }
    }

    return 0;
}