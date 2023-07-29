/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Escalator Conversations

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define mod 998244353
#define N 300005
#define deb(x) cerr << #x << " = " << x << nl

void solve() {
    int n, m, k, h;
    cin >> n >> m >> k >> h;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    
    int ans = 0;
    for (auto x : a) {
        int diff = abs(h - x);
        if (diff % k == 0 && diff > 0 && diff <= ((m - 1) * k)) {
            ans++;
        }
    }
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