/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Digital string maximization

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
    string ans;
    for (int i = 0; i < n; i++) {
        ans += s[i];
        int j = ans.size() - 1;
        while (j >= 1 && ans[j] != '0' && ((char) ans[j] - 1) > ans[j - 1]) {
            ans[j]--;
            swap(ans[j], ans[j - 1]);
            j--;
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