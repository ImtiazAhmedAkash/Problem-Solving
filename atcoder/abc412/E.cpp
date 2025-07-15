/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// E - LCM Sequence

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
const int N = 1e7;

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

void solve() {
    ll l, r;
    cin >> l >> r;
    
    ll ans = 1;
    l++; // LCM for (1, 2,..., l is already included in the answer)
    
    vector<bool> new_isPrime(r - l + 1, true);
    for (auto &x : prime) {
        for (ll i = (l + x - 1) / x * x; i <= r; i += x) {
            if (new_isPrime[i - l]) {
                new_isPrime[i - l] = false;
                ll tmp = i;
                while (tmp % x == 0) {
                    tmp /= x;
                }
                if (tmp == 1) {
                    ans++; // only prime power increases the LCM value
                }
            }
        }
    }
    
    for (int i = 0; i <= r - l; i++) {
        if (new_isPrime[i]) {
            ans++; // a new prime value also increases the LCM value
        }
    }
    
    cout << ans << nl;
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