// Calculating Function

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
 * If n is an odd number, the answer will be negative.
 * The answer will be: n/2 when n is even, and (n + 1)/2 when n is odd.
 *
 * A different approach:
 * ceil(n / 2.0) gives (n / 2) when n is even and gives (n + 1) / 2 when n is odd.
 * ceil function works on double values. That's why we have divided n by 2.0 and not 2.
 * Double values is shown is scienctific notation (like 1e+05) when the value is large.
 * In order to avoid that, we have typecasted the value into long long.
 * This logic is kept because there are lots of things to learn here.
 *
 * The easiest logic is: (n + 1) / 2
 * For odd number, it will print the value of ceil(n / 2.0).
 * And for even number, it will print the value of (n / 2.0).
 */

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;

    if (n & 1 == 1)
        cout << '-';

    // cout << (ll)ceil(n / 2.0) << '\n';
    cout << (n + 1) / 2 << '\n';

    return 0;
}