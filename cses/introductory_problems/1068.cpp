/*  In the name of ALLAH, the most gracious, the most merciful  */

// Weird Algorithm

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cout << #x << " = " << x << nl

/*
 * If a number is even, divide it by 2.
 * If the number is odd, multiply it by 3 and add 1.
 * Repeat this until the number is 1.
 * Use long long int. (For cases like 138367)
 */

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;

    while (n != 1)
    {
        cout << n << " ";

        if (n & 1)
            n = (3 * n) + 1;
        else
            n /= 2;
    }
    cout << n << nl;

    return 0;
}