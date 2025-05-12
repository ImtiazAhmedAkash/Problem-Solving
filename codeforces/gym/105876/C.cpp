/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// C - Prime Partition

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
const int N = 1e6;

vector<bool> isPrime(N + 5, true);
vector<ll> prime;
void sieve() {
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= N; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= N; j += i) {
                isPrime[j] = false;
            }
        }
    }
    
    for (int i = 2; i <= N; i++) {
        if (isPrime[i]) {
            prime.push_back(i);
        }
    }
}

bool good(ll x) {
    for (int i = 0; i < prime.size() && 1LL * prime[i] * prime[i] <= x; i++) {
        if (x % prime[i] == 0) return false;
    }
    return true;
}

void solve() {
    int n;
    cin >> n;
    
    if (n == 2) {
        cout << -1 << nl;
        return;
    }
    
    ll sum = 1LL * n * (n + 1) / 2;
    if (sum % 2 == 0) {
        cout << 2 << nl;
        return;
    }
    
    for (ll i = sum - 2; i >= 0; i -= 2) {
        if (good(i)) {
            cout << i << nl;
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    sieve();
    
    int T = 1;
    for (int t = 1; t <= T; t++) {
        solve();
    }
    
    return 0;
}