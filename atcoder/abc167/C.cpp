/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Skill Up

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
    int n, m, x;
    cin >> n >> m >> x;
    vector<int> C(n);
    vector A(n, vector(m, 0));
    for (int i = 0; i < n; i++) {
        cin >> C[i];
        for (int j = 0; j < m; j++) {
            cin >> A[i][j];
        }
    }
    ll ans = INF;
    for (int i = 0; i < (1 << n); i++) {
        ll cur = 0;
        vector<ll> lvl(m);
        for (int bit = 0; bit < n; bit++) {
            if (i & (1 << bit)) {
                cur += C[bit];
                for (int j = 0; j < m; j++) {
                    lvl[j] += A[bit][j];
                }
            }
        }
        bool ok = true;
        for (int j = 0; j < m; j++) {
            ok &= (x <= lvl[j]);
        }
        if (ok) {
            ans = min(ans, cur);
        }
    }
    cout << (ans == INF ? -1 : ans) << nl;
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