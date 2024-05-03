/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Maximize?

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;

void solve() {
    int x;
    cin >> x;
    int val = 0, ans = 0;
    for (int i = 1; i < x; i++) {
        int cur = gcd(x, i) + i;
        if (val < cur) {
            val = cur;
            ans = i;
        }
    }
    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        solve();
    }

    return 0;
}