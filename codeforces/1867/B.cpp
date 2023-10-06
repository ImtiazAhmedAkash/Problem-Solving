/*  In the Name of ALLAH, the most gracious, the most merciful  */

// XOR Palindromes

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
    string ans(n + 1, '0');
    int diff = 0;
    for (int i = 0; i < n / 2; i++) {
        if (s[i] != s[n - 1 - i]) diff++;
    }
    if (n & 1) {
        for (int i = diff; i <= n - diff; i++) ans[i] = '1';
    } else {
        for (int i = diff; i <= n - diff; i += 2) ans[i] = '1';
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