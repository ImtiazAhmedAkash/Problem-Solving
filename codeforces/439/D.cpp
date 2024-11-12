/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Devu and his Brother

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
    int n, m;
    cin >> n >> m;
    vector<int> A(n);
    for (auto &x : A) cin >> x;
    vector<int> B(m);
    for (auto &x : B) cin >> x;

    auto f = [&](int mid) -> ll {
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            ans += max(0, mid - A[i]);
        }
        for (int i = 0; i < m; i++) {
            ans += max(0, B[i] - mid);
        }
        return ans;
    };

    int L = 0, R = inf;
    while (R - L > 2) {
        int part = (R - L + 1) / 3;
        int m1 = L + part;
        int m2 = R - part;
        if (f(m1) < f(m2)) {
            R = m2 - 1;
        } else {
            L = m1 + 1;
        }
    }

    ll ans = INF;
    while (L <= R) {
        ans = min(ans, f(L++));
    }

    cout << ans << nl;
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