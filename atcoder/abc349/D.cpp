/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Divide Interval

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
    ll l, r;
    cin >> l >> r;
    vector<pair<ll, ll>> ans;
    while (l < r) {
        for (ll d = (1LL << 60); d > 0; d >>= 1) {
            if (l % d == 0) {
                ll x = l / d;
                if (d * (x + 1) <= r) {
                    x = d * (x + 1);
                    ans.push_back({l, x});
                    l = x;
                    break;
                }
            }
        }
    }
    cout << ans.size() << nl;
    for (auto [x, y] : ans) {
        cout << x << " " << y << nl;
    }
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