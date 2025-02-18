/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// E - GCD of Subset

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

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> A(n + 1);
    vector<int> mp(N + 5);
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        mp[A[i]]++;
    }
    
    vector<int> cnt(N + 5);
    cnt[1] = n;
    for (int i = 2; i <= N; i++) {
        for (int j = i; j <= N; j += i) {
            cnt[i] += mp[j];
        }
    }
    
    vector<int> ans(N + 5, 1);
    for (int i = 2; i <= N; i++) {
        for (int j = i; j <= N; j += i) {
            if (cnt[i] >= k) {
                ans[j] = max(ans[j], i);
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        cout << ans[A[i]] << nl;
    }
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