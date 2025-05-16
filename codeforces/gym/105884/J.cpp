/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// J - LCM Factorization

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "Dbug.h"
#else
#define dbg(...)
#endif

using ll = long long;
constexpr char nl = '\n';

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 3e5 + 5;

vector<int> fact(N + 5), invFact(N + 5);
int power(int a, int b) {
    int ans = 1;
    while (b) {
        if (b & 1) ans = 1LL * ans * a % mod;
        a = 1LL * a * a % mod;
        b /= 2;
    }
    return ans;
}
int inverseMod(int a) {
    return power(a, mod - 2);
}
void precalculate() {
    fact[0] = 1;
    for (int i = 1; i <= N; i++) {
        fact[i] = 1LL * fact[i - 1] * i % mod;
    }
    invFact[N] = inverseMod(fact[N]);
    for (int i = N - 1; i >= 0; i--) {
        invFact[i] = 1LL * invFact[i + 1] * (i + 1) % mod;
    }
}
int nCr(int n, int r) {
    if (n == 0 || n < r) return 0;
    return 1LL * fact[n] * invFact[r] % mod * invFact[n - r] % mod;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> cnt(n + 1);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    
    ll ans = 0;
    vector<bool> isPrime(n + 5, true);
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            int good = 0;
            for (int j = i; j <= n; j += i) {
                isPrime[j] = false;
                good += cnt[j]; 
            }
            ans += 1LL * i * (nCr(n, k) - nCr(n - good, k) + mod) % mod;
            ans %= mod;
        }
    }
    
    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    precalculate();
    
    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        solve();
    }
    
    return 0;
}