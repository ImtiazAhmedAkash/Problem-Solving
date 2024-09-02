/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Iris and Game on the Tree

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
    vector<int> degree(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        degree[u]++;
        degree[v]++;
    }
    string s;
    cin >> s;
    s = "-" + s;

    vector<int> cnt(2);
    int what = 0;
    int other = 0;
    for (int i = 2; i <= n; i++) {
        if (degree[i] == 1) {
            if (s[i] == '?')
                what++;
            else
                cnt[s[i] - '0']++;
        } else if (s[i] == '?') {
            other++;
        }
    }

    int ans = 0;
    if (s[1] == '?') {
        ans = max(cnt[0], cnt[1]) + (what / 2);
        if (cnt[0] == cnt[1] && (what & 1) && (other & 1)) {
            ans++;
        }
    } else {
        ans = cnt[1 ^ (s[1] - '0')] + (what + 1) / 2;
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