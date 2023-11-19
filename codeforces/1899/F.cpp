/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Alex's whims

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
    int n, q;
    cin >> n >> q;
    vector<int> D(q);
    for (auto &x : D) {
        cin >> x;
    }
    for (int i = 1; i + 1 <= n; i++) {
        cout << i << " " << i + 1 << nl;
    }
    int u = n, v = n - 1;
    for (auto x : D) {
        if (v == x) {
            cout << "-1 -1 -1" << nl;
        } else {
            cout << u << " " << v << " " << x << nl;
            v = x;
        }
    }
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