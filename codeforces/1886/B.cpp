/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Fear of the Dark

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
    pair<int, int> a{0, 0}, p, c1, c2;
    cin >> p.first >> p.second;
    cin >> c1.first >> c1.second;
    cin >> c2.first >> c2.second;
    
    auto dist = [&](pair<int, int> x, pair<int, int> y) {
        return hypot(x.first - y.first, x.second - y.second);
    };
    
    long double ans = min({
        max(dist(c1, a), dist(c1, p)),
        max(dist(c2, a), dist(c2, p)),
        max({dist(c1, a), dist(c1, c2) / 2, dist(c2, p)}),
        max({dist(c2, a), dist(c1, c2) / 2, dist(c1, p)})
    });
    
    cout << fixed << setprecision(9);
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