/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Hossam and Friends

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = (1 << 30);
const ll INF =(1LL << 62);
const int mod = 998244353;
const int N = 2e5 + 5;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1, n + 1);
    while (m--) {
        int x, y;
        cin >> x >> y;
        if (x > y) swap(x, y);
        a[x] = min(a[x], y);
    }
    ll ans = 0;
    for (int i = n - 1; i >= 1; i--) {
        a[i] = min(a[i], a[i + 1]);
    }
    for (int i = 1; i <= n; i++) {
        ans += a[i] - i;
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