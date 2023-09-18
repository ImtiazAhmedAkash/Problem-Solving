/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Longest Palindrome

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
    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
        string t = "";
        for (int j = i; j < s.size(); j++) {
            t += s[j];
            string u (t.rbegin(), t.rend());
            if (t == u) {
                ans = max(ans, (int) t.size());
            }
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