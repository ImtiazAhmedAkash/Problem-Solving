/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Canine Poetry

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define mod 998244353
#define N 300005
#define deb(x) cerr << #x << " = " << x << nl

void solve() {
    string s;
    cin >> s;
    s += '1';
    int ans = 0;
    for (int i = 1; i + 1 < s.size(); i++) {
        if (s[i - 1] == s[i + 1] && s[i + 1] != '@') {
            s[i + 1] = '@';
            ans++;
        }
        if (s[i] == s[i - 1] && s[i] != '@') {
            s[i] = '@';
            ans++;
        }
        
    }
    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}