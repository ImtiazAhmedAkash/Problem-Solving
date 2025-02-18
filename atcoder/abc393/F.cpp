/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// F - Prefix LIS Query

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
    int n, q;
    cin >> n >> q;
    vector<int> A(n);
    for (auto &x : A) {
        cin >> x;
    }
    
    vector<array<int, 3>> queries(q);
    for (int i = 0; i < q; i++) {
        int r, x;
        cin >> r >> x;
        queries[i] = {r - 1, x, i};
    }
    sort(queries.begin(), queries.end());
    
    vector<int> dp, ans(q);
    for (int i = 0, j = 0; i < n; i++) {
        auto it = lower_bound(dp.begin(), dp.end(), A[i]);
        if (it == dp.end()) {
            dp.push_back(A[i]);
        }
        else {
            *it = A[i];
        }
        
        while (j < q && queries[j][0] == i) {
            auto [_id, val, id] = queries[j];
            ans[id] = upper_bound(dp.begin(), dp.end(), val) - dp.begin();
            j++;
        }
    }
    
    for (int i = 0; i < q; i++) {
        cout << ans[i] << nl;
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