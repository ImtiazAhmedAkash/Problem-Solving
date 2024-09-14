/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Cross Explosion

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
    int h, w, q;
    cin >> h >> w >> q;

    set<pair<int, int>> R, C;

    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            R.insert({i, j});
            C.insert({j, i});
        }
    }

    int ans = h * w;
    while (q--) {
        int x, y;
        cin >> x >> y;
        if (R.find({x, y}) != R.end()) {
            ans--;
            R.erase({x, y});
            C.erase({y, x});
            continue;
        }

        auto it = R.lower_bound({x, y});
        if (it != R.begin()) {
            it--;
            auto [a, b] = *(it);
            if (a == x) {
                R.erase({a, b});
                C.erase({b, a});
                ans--;
            }
        }

        it = R.upper_bound({x, y});
        if (it != R.end()) {
            auto [a, b] = *(it);
            if (a == x) {
                R.erase({a, b});
                C.erase({b, a});
                ans--;
            }
        }

        it = C.lower_bound({y, x});
        if (it != C.begin()) {
            it--;
            auto [a, b] = *(it);
            if (a == y) {
                C.erase({a, b});
                R.erase({b, a});
                ans--;
            }
        }

        it = C.upper_bound({y, x});
        if (it != C.end()) {
            auto [a, b] = *(it);
            if (a == y) {
                C.erase({a, b});
                R.erase({b, a});
                ans--;
            }
        }
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