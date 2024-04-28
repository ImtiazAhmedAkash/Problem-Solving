/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Conveyor Belts

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
    int n, x1, y1, x2, y2;
    cin >> n >> x1 >> y1 >> x2 >> y2;

    int a = min({x1, n - x1 + 1, y1, n - y1 + 1});
    int b = min({x2, n - x2 + 1, y2, n - y2 + 1});
    cout << abs(a - b) << nl;
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