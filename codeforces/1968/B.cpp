/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Prefiquence

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
    int n, m;
    cin >> n >> m;
    string a, b;
    cin >> a >> b;

    int ans = 0;
    for (int l = 0, r = 0; l < n; l++) {
        while (r < m && a[l] != b[r]) {
            r++;
        }
        if (r < m && a[l] == b[r]) ans++, r++;
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