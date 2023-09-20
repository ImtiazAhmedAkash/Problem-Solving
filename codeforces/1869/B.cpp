/*  In the Name of ALLAH, the most gracious, the most merciful  */

// 2D Traveling

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;

void solve() {
    int n, k, a, b;
    cin >> n >> k >> a >> b;
    vector<pair<ll, ll>> A(n + 1), B;
    for (int i = 1; i <= n; i++) {
        ll x, y;
        cin >> x >> y;
        A[i] = {x, y};
        if (i <= k) {
            B.push_back({x, y});
        }
    }
    ll ans = abs(A[a].first - A[b].first) + abs(A[a].second - A[b].second);
    if (a <= k && b <= k) {
        ans = 0;
    } else {
        ll ac = (a <= k) ? 0 : INF;
        ll bc = (b <= k) ? 0 : INF;
        for (int i = 0; i < B.size(); i++) {
            ac = min(ac, abs(A[a].first - B[i].first) + abs(A[a].second - B[i].second));
            bc = min(bc, abs(A[b].first - B[i].first) + abs(A[b].second - B[i].second));
        }
        ans = min(ans, ac + bc);
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