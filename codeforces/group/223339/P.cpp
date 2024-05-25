/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Log2

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 1e5;

int fun(ll n) {
    if (n < 2) return 0;
    return 1 + fun(n / 2);
}

void solve() {
    ll n;
    cin >> n;
    cout << fun(n) << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    for (int t = 1; t <= T; t++) {
        solve();
    }

    return 0;
}