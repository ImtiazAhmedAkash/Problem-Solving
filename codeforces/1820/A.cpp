/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Yura's New Name

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
    string s;
    cin >> s;
    
    if (s == "^") {
        cout << 1 << nl;
        return;
    }
    
    int n = s.size();
    
    int ans = 0;
    int v = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '^') v++;
        if (s[i] == '_') {
            int j = i;
            int cnt = 0;
            while (j < n && s[i] == s[j]) {
                cnt++, j++;
            }
            ans += cnt - 1;
            if (i == 0) ans++;
            if (j == n) ans++;
            
            i = j - 1;
        }
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