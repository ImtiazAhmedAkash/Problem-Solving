/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Financial Instability

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
    vector<int> cnt(2);
    for (auto &c : s) {
        cnt[c - 'A']++;
    }
    
    if ((cnt[0] & 1) || (cnt[1] & 1)) {
        cout << "NO" << nl;
        return;
    }
    
    int n = s.size();
    int nA = cnt[0] / 2;
    int nB = cnt[1] / 2;
    
    vector<int> cur(2);
    for (int l = 0, r = 0; r < n; r++) {
        cur[s[r] - 'A']++;
        
        if (cur[0] == nA && cur[1] == nB) {
            cout << "YES" << nl;
            cout << l + 1 << " " << r + 2 << nl;
            return;
        }
        
        if (cur[0] + cur[1] == nA + nB) {
            cur[s[l] - 'A']--;
            l++;
        }
    }
    
    cout << "NO" << nl;
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