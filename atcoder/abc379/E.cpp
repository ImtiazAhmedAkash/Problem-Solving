/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Sum of All Substrings

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
    
    s = '!' + s;
    
    vector<ll> pref(n + 1);
    for (int i = 1; i <= n; i++) {
        int val = s[i] - '0';
        pref[i] = pref[i - 1] + val * i;
    }
    
    string ans;
    ll carry = 0;
    for (int i = n; i > 0; i--) {
        ll val = carry + pref[i];
        int last = val % 10;
        ans += (last + '0');
        carry = val / 10;
    }
    
    while (carry) {
        int last = carry % 10;
        ans += (last + '0');
        carry /= 10;
    }
    
    reverse(ans.begin(), ans.end());
    
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