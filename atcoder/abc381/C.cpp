/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// 11/22 Substring

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
    string s;
    cin >> s;
    
    s = "-" + s;
    vector<int> pref(n + 1);
    for (int i = 1; i <= n; i++) {
        if (s[i] == '1') {
            pref[i] = 1 + pref[i - 1];
        }
    }
    
    vector<int> suff(n + 2);
    for (int i = n; i >= 1; i--) {
        if (s[i] == '2') {
            suff[i] = 1 + suff[i + 1];
        }
    }
    
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '/') {
            ans = max(ans, 1 + 2 * min(pref[i - 1], suff[i + 1]));
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