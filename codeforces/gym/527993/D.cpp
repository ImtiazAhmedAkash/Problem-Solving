/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Geometry Class

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;
const long double pi = acos(-1.0);

void solve() {
    long double a, b, c;
    cin >> a >> b >> c;

    int A = round(asin(a) * 180.0 / pi);
    int B = round(asin(b) * 180.0 / pi);
    int C = round(asin(c) * 180.0 / pi);

    if (A + B + C != 180) {
        int mx = max({A, B, C});
        if (A == mx) {
            A = 180 - B - C;
        } else if (B == mx) {
            B = 180 - A - C;
        } else {
            C = 180 - B - A;
        }
    }

    cout << max({A, B, C}) << nl;
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