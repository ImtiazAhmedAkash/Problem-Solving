/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Theatre Square

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
 * Check how many flagstones are needed to cover the width and length separately.
 * If the length or width is divisible by 'a' or the size of the flagstone, (n / a) flagstone is needed.
 * Or else (n / a) + 1 flagstone will be needed. The same goes for the width.
 * (n + a - 1) / n gives (n / a) if n is divisible by a, otherwise, it gives (n / a) + 1.
 * Finally, multiply m and n to find how many flagstones are needed to cover the entire area.
 */

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n, m, a;
    cin >> n >> m >> a;
    
    n = (n + a - 1) / a;
    m = (m + a - 1) / a;
    
    cout << m * n << '\n';

    return 0;
}