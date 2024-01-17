/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Square

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
    int xmx = -inf, xmn = inf, ymx = -inf, ymn = inf;
    for (int i = 0; i < 4; i++) {
        int x, y;
        cin >> x >> y;
        xmx = max(xmx, x);
        xmn = min(xmn, x);
        ymx = max(ymx, y);
        ymn = min(ymn, y);
    }
    cout << 1LL * (xmx - xmn) * (ymx - ymn) << nl;
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