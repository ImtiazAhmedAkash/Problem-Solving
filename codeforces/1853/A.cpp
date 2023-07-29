/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Desorting

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define mod 998244353
#define N 300005
#define deb(x) cerr << #x << " = " << x << nl

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    int diff = INF, ans = 0;
    for (int i = 0; i + 1 < n; i++) {
        diff = min(diff, a[i + 1] - a[i]);
    }
    if (diff >= 0) ans = (diff + 2) / 2;
    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}