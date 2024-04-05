/*  In the Name of ALLAH, the most gracious, the most merciful  */

// PWRANDMOD - Power and Mod

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define uint128 unsigned __int128
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int N = 2e5 + 5;

ull mulmod(ull a, ull b, uint128 mod) {
    ull ans = 0;
    while (b) {
        if (b & 1) ans = ((uint128)ans + a) % mod;
        a = ((uint128)a + a) % mod;
        b >>= 1;
    }
    return ans;
}

ull power(ull a, ull b, uint128 mod) {
    ull ans = 1;
    while (b) {
        if (b & 1) ans = mulmod(ans, a, mod);
        a = mulmod(a, a, mod);
        b >>= 1;
    }
    return ans;
}

void solve() {
    int a, b;
    cin >> a >> b;
    string s;
    cin >> s;
    uint128 mod = 0;
    for (auto c : s) {
        mod = (mod * 10) + (c - '0');
    }
    cout << power(a, b, mod) << nl;
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