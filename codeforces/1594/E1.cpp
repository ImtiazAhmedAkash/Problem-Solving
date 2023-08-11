/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Rubik's Cube Coloring (Easy Version)

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define N 300005
#define deb(x) cerr << #x << " = " << x << nl
const ll mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    ll ans = 6;
    if (n > 1) {
        ll tmp = 4;
        for (int i = 2; i <= n; i++) {
            tmp = (tmp * tmp) % mod;
            ans = (ans * tmp) % mod;
        }
    }
    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    while (t--)
        solve();

    return 0;
}