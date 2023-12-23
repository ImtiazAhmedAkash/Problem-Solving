/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Repsept

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
    int cur = 0, ans = -1;
    for (int i = 1; i <= n; i++) {
        cur = cur * 10 + 7;
        cur %= n;
        if (cur == 0) {
            ans = i;
            break;
        }
    }
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