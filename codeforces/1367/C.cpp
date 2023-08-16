/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Social Distance

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define N 300005
#define deb(x) cerr << #x << " = " << x << nl
const ll mod = 998244353;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    
    int ans = 0;
    if (s.find('1') == string::npos) {
        for (int i = 0; i < n; i += (k + 1)) ans++;
    } else {
        vector<int> a;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') a.push_back(i);
        }
        
        for (int i = a.front(); i >= 0; i -= (k + 1)) {
            if (s[i] == '0') ans++;
        }
        
        for (int i = a.back(); i < n; i += (k + 1)) {
            if (s[i] == '0') ans++;
        }
        
        for (int i = 1; i < a.size(); i++) {
            int dist = a[i] - a[i - 1];
            ans += max(0, ((dist - k - 1) / (k + 1)));
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