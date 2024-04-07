/*  In the Name of ALLAH, the most gracious, the most merciful  */

// ZSUM - Just Add It

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 10000007;
const int N = 2e5 + 5;

int power(int a, int b) {
    int ans = 1;
    while (b) {
        if (b & 1) ans = 1LL * ans * a % mod;
        a = 1LL * a * a % mod;
        b >>= 1;
    }
    return ans;
}

void solve() {
    int n, k;
    while (cin >> n >> k && n && k) {
        int ans = (2 * power(n - 1, k) + power(n, k) + 2 * power(n - 1, n - 1) + power(n, n)) % mod;
        cout << ans << nl;
    }
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