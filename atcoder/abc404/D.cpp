/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// D - Goin' to the Zoo

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
const int N = 2e5 + 5;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> C(n);
    for (auto &x : C) cin >> x;
    vector zoo(n, vector<int>());
    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;
        while (k--) {
            int x;
            cin >> x;
            --x;
            zoo[x].push_back(i);
        }
    }
    
    ll ans = INF;
    for (int mask = 1; mask < (1 << (2 * n)); mask++) {
        ll cur = 0;
        vector<int> used(m, 0);
        for (int bit = 0; bit < 2 * n; bit++) {
            if (mask & (1 << bit)) {
                cur += C[bit % n];
                for (auto &x : zoo[bit % n]) {
                    used[x]++;
                }
            }
        }
        bool ok = true;
        for (int i = 0; i < m; i++) {
            ok &= (used[i] >= 2);
        }
        
        if (ok) {
            ans = min(ans, cur);
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