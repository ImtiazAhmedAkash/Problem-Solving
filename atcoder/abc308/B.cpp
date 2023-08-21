/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Default Price

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define N 300005
#define deb(x) cerr << #x << " = " << x << nl
const ll mod = 998244353;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> eaten(n), given(m);
    for (int i = 0; i < n; i++) cin >> eaten[i];
    for (int i = 0; i < m; i++) cin >> given[i];
    
    int def;
    cin >> def;
    map<string, int> mp;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        mp[given[i]] = x;
    }
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (mp.count(eaten[i])) {
            ans += mp[eaten[i]];
        } else ans += def;
    }
    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    while (t--) {
        solve();
    }
    
    return 0;
}