/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// E - Interesting Ratio

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "Dbug.h"
#else
#define dbg(...)
#endif

using ll = long long;
constexpr char nl = '\n';

const int inf = 2e9;
const ll INF = 1e18;
const int mod = 1e9 + 7;
const int N = 1e7;

vector<bool> isPrime(N + 5, true);
vector<int> prime;
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
    int n;
    cin >> n;
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        int x = upper_bound(prime.begin(), prime.end(), n / i) - prime.begin();
        ans += x;
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