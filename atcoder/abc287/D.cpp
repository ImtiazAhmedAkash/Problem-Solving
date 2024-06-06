/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Match or Not

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
    string s, t;
    cin >> s >> t;
    int n = t.size();
    int m = s.size();
    vector<bool> pref(n + 1, true), suff(n + 2, true);
    for (int i = 1; i <= n; i++) {
        pref[i] = (pref[i - 1] & (s[i - 1] == t[i - 1] || s[i - 1] == '?' || t[i - 1] == '?'));
    }
    for (int i = 0; i < n; i++) {
        suff[n - i] = (suff[n - i + 1] & (s[m - i - 1] == t[n - i - 1] || s[m - i - 1] == '?' || t[n - i - 1] == '?'));
    }
    for (int i = 0; i <= n; i++) {
        cout << (pref[i] && suff[i + 1] ? "Yes" : "No") << nl;
    }
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