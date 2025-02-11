/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// Skibidus and Capping

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "Dbug.h"
#else
#define dbg(...)
#endif

using ll = long long;
constexpr char nl = '\n';
#define deb(x) cerr << #x << ": " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5;

vector<bool> isPrime(N + 5, true);
vector<int> spf(N + 5);
void sieve() {
    iota(spf.begin(), spf.end(), 0);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= N; i++) {
        if (isPrime[i]) {
            for (int j = 2 * i; j <= N; j += i) {
                isPrime[j] = false;
                spf[j] = min(spf[j], i);
            }
        }
    }
}
vector<int> factorize(int n) {
    vector<int> v;
    while (n != 1) {
        int x = spf[n];
        v.push_back(x);
        n /= x;
    }
    return v;
}

void solve() {
    int n;
    cin >> n;
    vector<int> cnt(n + 1);
    set<int> prime, semiPrime;
    int primeCount = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
        if (isPrime[x]) {
            prime.insert(x);
            primeCount++;
        }
        if (factorize(x).size() == 2) {
            semiPrime.insert(x);
        }
    }

    ll ans = 0;

    // semi-prime = prime1 * prime2
    for (auto &x : prime) {
        primeCount -= cnt[x];
        ans += 1LL * cnt[x] * primeCount;
    }

    // if 'x' is a semi-prime number having two distinct prime divisor 'y' and 'z'
    // x = lcm(x, x) = lcm(x, y) = lcm(x, z)
    for (auto &x : semiPrime) {
        vector<int> v = factorize(x);
        int y = v.front();
        int z = v.back();
        ans += 1LL * cnt[x] * (cnt[x] + 1) / 2;
        ans += 1LL * cnt[x] * cnt[y];
        if (y != z) ans += 1LL * cnt[x] * cnt[z];
    }

    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    sieve();

    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        solve();
    }

    return 0;
}