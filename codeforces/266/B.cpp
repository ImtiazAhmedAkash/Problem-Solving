// Queue at the School

#include <bits/stdc++.h>
using namespace std;

/*
 * Traverse the string backwards. (Personal preference, no other particular reason)
 * T represents for how many seconds the swapping operation will be done.
 * If str[i] == 'G' and str[i - 1] == 'B', (i.e. a boy is in front of a girl) swap them and decrement i by 1.
 * Because, after swapping operation, i will be i - 1.
 * As, in the previous operation, str[i - 1] was swapped with str[i],
 * for the next checking, i will be i - 2.
 * i will be decremented by one in the if condition, and again by one in the for loop.
 */

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, t;
    cin >> n >> t;

    string str;
    cin >> str;

    while (t--)
    {
        for (int i = n - 1; i > 0; i--)
        {
            if (str[i] == 'G' && str[i - 1] == 'B')
            {
                swap(str[i], str[i - 1]);
                i--;
            }
        }
    }

    cout << str << '\n';

    return 0;
}