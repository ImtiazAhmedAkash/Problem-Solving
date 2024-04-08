/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Fedya and Maths

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 5;
const int N = 2e5 + 5;

int power(int a, int b) {
    int ans = 1;
    while (b) {
        if (b & 1) ans = ans * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

void solve() {
    string s;
    cin >> s;
    int n = 0;
    for (auto c : s) {
        n = n * 10 + (c - '0');
        n %= (mod - 1);
    }
    int ans = 0;
    for (int i = 1; i < mod; i++) {
        ans += power(i, n);
        ans %= mod;
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