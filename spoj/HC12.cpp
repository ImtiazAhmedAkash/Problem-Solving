/*  In the Name of ALLAH, the most gracious, the most merciful  */

// HC12 - Card Game

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 1000000007;
const int N = 10000;

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
    if (n < r) return 0;
    return 1LL * fact[n] * invFact[r] % mod * invFact[n - r] % mod;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> A(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());

    ll ans = 0;
    for (int i = n; i > 0; i--) {
        ll cur = 1LL * A[i] * nCr(i - 1, k - 1) % mod;
        ans += cur;
        ans %= mod;
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
        cout << "Case #" << t << ": ";
        solve();
    }

    return 0;
}