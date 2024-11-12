/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// ICM2003 - Is This JEE

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;
const double pi = acos(-1);

void solve() {
    double b, c;
    cin >> b >> c;

    auto f = [&](double x) -> double {
        return (x * x + b * x + c) / sin(x);
    };

    double L = 0, R = pi / 2;
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

    cout << fixed << setprecision(10);
    cout << f((L + R) / 2) << nl;
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