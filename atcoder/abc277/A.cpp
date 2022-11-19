/*  In the Name of ALLAH, the most gracious, the most merciful  */

// ^{-1}

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cout << #x << " = " << x << nl

/*
 * Perform a linear search on a 1-indexed array to find 'k'.
 * Print the index of 'k'.
 */

void solve()
{
    int n, k;
    cin >> n >> k;

    int val, ans;

    for (int i = 1; i <= n; i++)
    {
        cin >> val;
        if (val == k)
            ans = i;
    }

    cout << ans << nl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}