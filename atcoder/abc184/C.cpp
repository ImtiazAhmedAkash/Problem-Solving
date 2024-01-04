/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Super Ryuma

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
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int x = a - c;
    int y = b - d;
    int ans = 3;
    if (x == 0 && y == 0)
        ans = 0;
    else if (x == y || x == -y || abs(x) + abs(y) <= 3)
        ans = 1;
    else if (((a + b + c + d) % 2 == 0) || abs(x + y) <= 3 || abs(x - y) <= 3 || abs(x) + abs(y) <= 6)
        ans = 2;
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