/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// AMCS03 - Race Time!

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
    int n, k;
    cin >> n >> k;
    vector<int> S(n), D(n);
    for (int i = 0; i < n; i++) {
        cin >> S[i] >> D[i];
    }

    auto f = [&](double mid) -> double {
        double mx = 0;
        double mn = INF;
        for (int i = 0; i < n; i++) {
            double pos = S[i] * mid + D[i];
            mx = max(mx, pos);
            mn = min(mn, pos);
        }
        return mx - mn;
    };

    double L = 0, R = k;
    for (int i = 0; i < 100; i++) {
        double part = (R - L) / 3;
        double m1 = L + part;
        double m2 = R - part;
        if (f(m1) < f(m2)) {
            R = m2;
        } else {
            L = m1;
        }
    }

    cout << fixed << setprecision(6);
    cout << f((L + R) / 2) << nl;
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