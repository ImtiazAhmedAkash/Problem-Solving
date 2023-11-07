/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Counting Test

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
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    s = "+" + s;
    
    vector pref(26, vector<ll> (n + 1));
    for (int i = 1; i < s.size(); i++) {
        pref[s[i] - 'a'][i] = 1;
    }
    for (int i = 0; i < 26; i++) {
        partial_sum(pref[i].begin(), pref[i].end(), pref[i].begin());
    }
    
    auto Count = [&] (int r, char c) {
        ll ans = pref[c - 'a'].back() * (r / n);
        r %= n;
        ans += pref[c - 'a'][r];
        return ans;
    };
    
    while (q--) {
        int l, r;
        char c;
        cin >> l >> r >> c;
        cout << Count(r, c) - Count(l - 1, c) << nl;
    }
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