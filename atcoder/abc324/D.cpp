/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Square Permutation

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    ll N = 1;
    for (auto x : s) N *= 10;

    auto Count = [&](string t) {
        vector<int> ret(10);
        for (auto x : t) {
            ret[x - '0']++;
        }
        return ret;
    };

    vector<int> cnt = Count(s);
    int ans = 0;
    for (ll i = 0; i * i <= N; i++) {
        string cur = to_string(i * i);
        int zero = cnt[0] - count(cur.begin(), cur.end(), '0');
        for (int j = 0; j < zero; j++) {
            cur += '0';
        }
        auto v = Count(cur);
        if (cnt == v) ans++;
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