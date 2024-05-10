/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Card Game

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 60;

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
    int n;
    cin >> n;

    auto fun = [&](auto self, int n, bool isAlex) -> ll {
        if (n == 2) {
            return isAlex ? 1 : 0;
        }
        ll ans = 0;
        if (isAlex) {
            ans = nCr(n - 1, (n / 2) - 1);
            ans += self(self, n - 2, false);
            ans %= mod;
        } else {
            ans = nCr(n - 2, (n / 2) - 2);
            ans += self(self, n - 2, true);
            ans %= mod;
        }
        return ans;
    };

    ll alex = fun(fun, n, true);
    ll boris = fun(fun, n, false);
    ll draw = nCr(n, n / 2) - (alex + boris);
    draw += mod;
    draw %= mod;
    cout << alex << " " << boris << " " << draw << nl;
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