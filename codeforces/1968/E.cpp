/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Cells Arrangement

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

    int x = 1, y = 1;
    cout << x << " " << y << nl;
    cout << n << " " << n << nl;

    if (n == 2) return;

    for (int i = 1; i <= n - 3; i++) {
        cout << ++x << " " << y << nl;
    }
    cout << 1 << " " << n - 1 << nl;
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