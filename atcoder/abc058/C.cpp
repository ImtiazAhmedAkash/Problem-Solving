/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Dubious Document

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
    vector<int> cnt(26, inf);
    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        vector<int> cur(26, 0);
        for (auto x : s) {
            cur[x - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            cnt[i] = min(cnt[i], cur[i]);
        }
    }
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < cnt[i]; j++) {
            cout << (char)(i + 'a');
        }
    }
    cout << nl;
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