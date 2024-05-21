/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Moves on Binary Tree

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
    ll n, x;
    cin >> n >> x;
    string s;
    cin >> s;
    string t = "";
    for (int bit = __lg(x); bit >= 0; bit--) {
        t += ((x >> bit) & 1) ? '1' : '0';
    }
    for (auto c : s) {
        if (c == 'U') {
            t.pop_back();
        } else if (c == 'L') {
            t += '0';
        } else if (c == 'R') {
            t += '1';
        }
    }
    reverse(t.begin(), t.end());
    ll ans = 0;
    for (int bit = 0; bit < t.size(); bit++) {
        if (t[bit] == '1') {
            ans |= (1LL << bit);
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