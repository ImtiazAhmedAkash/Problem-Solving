/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Meeting on the Line

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const double eps = 1e-9;
const int mod = 998244353;
const int N = 2e5 + 5;

void solve() {
    int n;
    cin >> n;
    vector<int> X(n), T(n);
    for (auto &x : X) cin >> x;
    for (auto &x : T) cin >> x;

    auto check = [&](double mid) -> pair<double, double> {
        double l = -inf, r = inf;
        for (int i = 0; i < n; i++) {
            if (mid < T[i]) {
                return {inf, -inf};
            }
            double x = X[i] - (mid - T[i]);
            double y = X[i] + (mid - T[i]);
            l = max(l, x);
            r = min(r, y);
        }
        return {l, r};
    };

    double L = 0, R = inf;
    for (int i = 0; i < 100; i++) {
        double M = (L + R) / 2;
        auto [l, r] = check(M);
        if (l + eps <= r) {
            R = M;
        } else {
            L = M;
        }
    }

    auto ans = check(R);
    cout << fixed << setprecision(10);
    cout << ans.first << nl;
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