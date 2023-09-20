/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Binary Strings are Fun

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = (1 << 30);
const ll INF = (1LL << 62);
const int mod = 998244353;
const int N = 2e5 + 5;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    ll ans = 1, cur = 1;
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i - 1]) cur = (cur * 2) % mod;
        else cur = 1;
        ans = (ans + cur) % mod;
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