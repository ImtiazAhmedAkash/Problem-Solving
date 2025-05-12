/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// D - The LCM Weave

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

vector<int> spf(N + 5);
void sieve() {
    iota(spf.begin(), spf.end(), 0);
    for (int i = 2; i * i <= N; i++) {
        if (spf[i] == i) {
            for (int j = i; j <= N; j += i) {
                spf[j] = min(spf[j], i);
            }
        }
    }
}

vector<int> prime_factorization(int n) {
    vector<int> v;
    while (n != 1) {
        if (v.empty() || v.back() != spf[n]) {
            v.push_back(spf[n]);
        }
        n /= spf[n];
    }
    return v;
}

void solve() {
    int n;
    cin >> n;
    vector<int> A(n);
    vector<int> mp(N + 5);
    for (auto &x : A) {
        cin >> x;
        mp[x]++;
    }
    
    int maxi = *max_element(A.begin(), A.end());
    vector<int> cnt(maxi + 5);
    for (int i = 2; i <= maxi; i++) {
        for (int j = i; j <= maxi; j += i) {
            cnt[i] += mp[j];
        }
    }
    
    auto inclusion_exclusion = [&](int x) -> int {
        if (x == 1) return n;
        
        vector<int> v = prime_factorization(x);
        int m = v.size();
        int ret = n;
        for (int mask = 1; mask < (1 << m); mask++) {
            int val = 1;
            for (int bit = 0; bit < m; bit++) {
                if (mask & (1 << bit)) {
                    val *= v[bit];
                }
            }
            if (__builtin_popcount(mask) & 1) {
                ret -= cnt[val];
            }
            else {
                ret += cnt[val];
            }
        }
        
        return ret;
    };
    
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += inclusion_exclusion(A[i]);
    }
    ans /= 2;
    
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