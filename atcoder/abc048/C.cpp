/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Boxes and Candies

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = (1 << 30);
const ll INF = (1LL << 62);
const int mod = 998244353;
const int N = 1e7 + 5;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] + a[i - 1] > x) {
            int extra = a[i] + a[i - 1] - x;
            ans += extra;
            a[i] -= extra;
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