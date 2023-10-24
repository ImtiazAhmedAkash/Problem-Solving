/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Rigged!

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
    int n;
    cin >> n;
    int x, y;
    cin >> x >> y;
    n--;
    int ans = x;
    while (n--) {
        int a, b;
        cin >> a >> b;
        if (a >= x && b >= y) ans = -1;
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