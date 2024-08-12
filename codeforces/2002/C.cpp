/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Black Circles

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
    int n;
    cin >> n;
    vector<int> L(n), R(n);
    for (int i = 0; i < n; i++) {
        cin >> L[i] >> R[i];
    }
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    auto dist = [&](int p, int q, int r, int s) -> ll {
        int x = abs(p - r);
        int y = abs(q - s);
        return 1LL * x * x + 1LL * y * y;
    };

    ll cur = dist(a, b, c, d);
    for (int i = 0; i < n; i++) {
        if (dist(L[i], R[i], c, d) <= cur) {
            cout << "NO" << nl;
            return;
        }
    }
    cout << "YES" << nl;
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