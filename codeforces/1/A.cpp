/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Theatre Square

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
 * We will check how many flagstones are needed to cover the width and length separately.
 * If the length or width is divisible by 'a' or the size of the flagstone, (n / a) flagstone is needed.
 * Or else (n / a) + 1 flagstone will be needed. The same goes for the width.
 * Finally, we will multiply m and n to find how many flagstones are needed to cover the entire area.
 * Here, (n % a != 0) returns 1 if n is not divisible by a, and 0 if n is divisible by a.
 */

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n, m, a;
    cin >> n >> m >> a;

    n = (n / a) + (n % a != 0);
    m = (m / a) + (m % a != 0);

    cout << m * n << '\n';

    return 0;
}