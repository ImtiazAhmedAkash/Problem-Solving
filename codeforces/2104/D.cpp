/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// D - Array and GCD

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
const int N = 6e6 + 5;

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
    
    prime.push_back(2);
    for (int i = 3; i <= N; i += 2) {
        if (isPrime[i]) {
            prime.push_back(i);
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (auto &x : A) cin >> x;
    
    sort(A.begin(), A.end(), greater());
    
    int ans = 0;
    ll have = 0;
    for (int i = 0, j = 0; i < n; i++) {
        if (A[i] >= prime[j]) {
            have += A[i] - prime[j];
            j++;
            continue;
        }
        
        if (A[i] + have >= prime[j]) {
            have -= prime[j] - A[i];
            j++;
        }
        else {
            ans++;
        }
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