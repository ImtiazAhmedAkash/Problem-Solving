/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Beautiful Numbers

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 1000000007;
const int N = 2e5 + 5;

int power(int a, int b) {
    int ans = 1;
    while (b) {
        if (b & 1) ans = 1LL * ans * a % mod;
        a = 1LL * a * a % mod;
        b >>= 1;
    }
    return ans;
}

int inverse(int a) {
    return power(a, mod - 2);
}

void solve() {
    int a, b, n;
    cin >> a >> b >> n;

    vector<int> fact(n + 1), invFact(n + 1);
    fact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = 1LL * i * fact[i - 1] % mod;
    }
    invFact[n] = inverse(fact[n]);
    for (int i = n - 1; i >= 0; i--) {
        invFact[i] = 1LL * invFact[i + 1] * (i + 1) % mod;
    }

    auto isGood = [&](int x) -> bool {
        while (x) {
            int rem = x % 10;
            if (rem != a && rem != b) return false;
            x /= 10;
        }
        return true;
    };

    int ans = 0;
    for (int i = 0; i <= n; i++) {
        int sum = a * i + b * (n - i);
        if (isGood(sum)) {
            int cur = 1LL * fact[n] * invFact[i] % mod * invFact[n - i] % mod;
            ans = (ans + cur) % mod;
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