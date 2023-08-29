/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Vampiric Powers, Anyone?

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int INF = (1 << 30);
const int mod = 998244353;
const int N = 2e5 + 5;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    for (int ans = (1 << 8) - 1; ans >= 0; ans--) {
        vector<bool> mp(256, false);
        mp[0] = 1;
        int xr = 0;
        for (int i = 0; i < n; i++) {
            xr ^= a[i];
            if (mp[ans ^ xr] == 1) {
                cout << ans << nl;
                return;
            }
            mp[xr] = 1;
        }
    }
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