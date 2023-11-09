/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Equation

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e4 + 5;
const double eps = 1e-9;

void solve() {
    double n;
    cin >> n;
    double L = 0, R = 1e6;
    while (L + eps < R) {
        double M = L + (R - L) / 2;
        double cur = M;
        cur += (M * M * M * M);
        if (cur <= n) L = M;
        else R = M;
    }
    double ans = L + (R - L) / 2;
    cout << fixed << setprecision(9);
    cout << ans * ans << nl;
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