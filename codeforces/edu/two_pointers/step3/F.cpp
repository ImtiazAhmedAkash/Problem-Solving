/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Card Substrings

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
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    vector<int> cnt(26);
    for (auto x : t) {
        cnt[x - 'a']++;
    }
    ll ans = 0;
    vector<int> cur(26);
    for (int l = 0, r = 0; r < n; r++) {
        cur[s[r] - 'a']++;
        while (l <= r && cnt[s[r] - 'a'] < cur[s[r] - 'a']) {
            cur[s[l] - 'a']--;
            l++;
        }
        ans += r - l + 1;
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