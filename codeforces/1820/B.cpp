/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// JoJo's Incredible Adventures

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
    
    int n = s.size();
    if (count(s.begin(), s.end(), '1') == 0) {
        cout << 0 << nl;
        return;
    }
    
    int indx = s.find('0');
    if (indx == -1) {
        cout << 1LL * n * n << nl;
        return;
    }
    
    s = s.substr(indx);
    for (int i = 0; i < indx; i++) {
        s += '1';
    }
    
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            int j = i;
            int cnt = 0;
            while (j < n && s[i] == s[j]) {
                cnt++, j++;
            }
            
            int k = (cnt + 1) / 2;
            ans = max(ans, 1LL * k * (cnt + 1 - k));
            
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