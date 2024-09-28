/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Triangle Coloring

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;

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
ll nCr(int n, int r) {
    if (n == 0 || n < r) return 0;
    return 1LL * fact[n] * invFact[r] % mod * invFact[n - r] % mod;
}

void solve() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (auto &x : A) cin >> x;

    int m = n / 3;
    ll ans = 1LL * nCr(m, m / 2);
    ans %= mod;

    while (!A.empty()) {
        vector<int> B;
        for (int i = 0; i < 3; i++) {
            B.push_back(A.back());
            A.pop_back();
        }
        sort(B.begin(), B.end(), greater());
        if (B[0] == B[2]) {
            ans *= 3;
            ans %= mod;
        } else if (B[1] == B[2]) {
            ans *= 2;
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
    for (int t = 1; t <= T; t++) {
        solve();
    }

    return 0;
}