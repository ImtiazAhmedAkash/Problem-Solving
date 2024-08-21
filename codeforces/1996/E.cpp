/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Decode

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 1e9 + 7;
const int N = 2e5 + 5;

void solve() {
    string s;
    cin >> s;

    int n = s.size();
    vector<int> pref(n + 1);
    map<int, vector<int>> M;
    M[0].push_back(0);
    for (int i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + (s[i] == '0' ? -1 : 1);
        M[pref[i + 1]].push_back(i + 1);
    }

    ll ans = 0;
    for (auto &[a, b] : M) {
        int m = b.size();
        if (m <= 1) continue;
        ll suff = 0;
        for (int i = m - 2; i >= 0; i--) {
            int x = b[i] + 1;
            int y = n - b[i + 1] + 1;
            suff += y;
            ans = (ans + x * suff % mod) % mod;
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