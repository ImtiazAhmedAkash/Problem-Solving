/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Making Anti-Palindromes

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

    vector<int> cnt(26);
    int mx = 0;
    for (auto &c : s) {
        cnt[c - 'a']++;
        mx = max(mx, cnt[c - 'a']);
    }
    if ((n & 1) || mx > n / 2) {
        cout << -1 << nl;
        return;
    }

    fill(cnt.begin(), cnt.end(), 0);

    int bad = 0;
    mx = 0;
    for (int i = 0; i < n / 2; i++) {
        if (s[i] == s[n - 1 - i]) {
            bad++;
            cnt[s[i] - 'a']++;
            mx = max(mx, cnt[s[i] - 'a']);
        }
    }
    cout << max((bad + 1) / 2, mx) << nl;
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