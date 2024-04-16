/*  In the Name of ALLAH, the most gracious, the most merciful  */

// How Many?

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 1e9 + 7;
const int N = 2e5 + 5;

int power(int a, int b) {
    int ans = 1;
    while (b) {
        if (b & 1) ans = 1LL * a * ans % mod;
        a = 1LL * a * a % mod;
        b >>= 1;
    }
    return ans;
}

int inverse(int a) {
    return power(a, mod - 2);
}

void solve() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    s = '!' + s;
    vector cnt(n + 1, vector<int>(26));
    for (int i = 1; i <= n; i++) {
        cnt[i][s[i] - 'a']++;
    }
    for (int j = 0; j < 26; j++) {
        for (int i = 1; i <= n; i++) {
            cnt[i][j] += cnt[i - 1][j];
        }
    }

    vector<int> fact(n + 1), invFact(n + 1);
    fact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = 1LL * i * fact[i - 1] % mod;
    }
    invFact[n] = inverse(fact[n]);
    for (int i = n - 1; i >= 0; i--) {
        invFact[i] = 1LL * invFact[i + 1] * (i + 1) % mod;
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        int ans = fact[r - l + 1];
        for (int i = 0; i < 26; i++) {
            int tmp = cnt[r][i] - cnt[l - 1][i];
            ans = 1LL * ans * invFact[tmp] % mod;
        }
        cout << (ans - 1 + mod) % mod << nl;
    }
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