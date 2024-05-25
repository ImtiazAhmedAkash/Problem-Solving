/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Reach Value

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;

int fun(ll cur, ll n) {
    if (cur == n) return 1;
    if (cur > n) return 0;
    return max(fun(cur * 10, n), fun(cur * 20, n));
}

void solve() {
    ll n;
    cin >> n;
    cout << (fun(1, n) ? "YES" : "NO") << nl;
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