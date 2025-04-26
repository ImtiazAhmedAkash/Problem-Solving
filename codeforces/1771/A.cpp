/*  In the Name of ALLAH, the most gracious, the most merciful  */

// A - Hossam and Combinatorics

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

void solve()
{
    multiset<ll> s;
    ll n, val, maxi = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        s.insert(val);
        maxi = max(maxi, val);
    }

    ll mini = *(s.begin());

    if (n == 1)
    {
        cout << 0 << nl;
        return;
    }

    ll max_count = count(s.begin(), s.end(), maxi);
    ll min_count = count(s.begin(), s.end(), mini);

    if (maxi == mini)
    {
        cout << max_count * (min_count - 1) << nl;
    }
    else
        cout << max_count * min_count * 2 << nl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}