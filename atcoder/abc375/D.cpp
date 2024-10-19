/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// ABA

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
    int n = s.size();

    vector at(26, vector<int>());
    for (int i = 0; i < n; i++) {
        at[s[i] - 'A'].push_back(i);
    }

    ll ans = 0;
    for (int i = 0; i < 26; i++) {
        ll sum = 0;
        auto v = at[i];
        int m = v.size();
        for (int j = m - 2; j >= 0; j--) {
            sum += v[j + 1];
            ans += sum - 1LL * (m - 1 - j) * (v[j] + 1);
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