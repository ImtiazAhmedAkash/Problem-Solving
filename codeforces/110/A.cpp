// Nearly Lucky Number

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
 * First, count the lucky digits (4 and 7) in the given number.
 * As the max length of n is 10^18, 
 * A number will be nearly lucky if it contains 4 or 7 lucky numbers.
 * Check the count, and print answer accordingly.
 */

ll mycount(ll num)
{
    ll c = 0;
    while (num > 0)
    {
        if (num % 10 == 4 || num % 10 == 7)
            c++;
        num /= 10;
    }
    return c;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;

    ll cnt = mycount(n);

    if (cnt == 4 || cnt == 7)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}