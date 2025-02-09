/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// Segment Trees ?

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
    int n;
    cin >> n;
    vector<int> A(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    
    int q;
    cin >> q;
    vector<array<int, 3>> queries;
    for (int i = 0; i < q; i++) {
        int op;
        cin >> op;
        if (op == 1) {
            int x, p;
            cin >> x >> p;
            queries.push_back({1, x, p});
        }
        else {
            int v;
            cin >> v;
            queries.push_back({2, v, 0});
        }
    }
    
    vector<int> ans(n + 1);
    vector<bool> used(n + 1);
    int mx = 0;
    for (int i = q - 1; i >= 0; i--) {
        auto [op, x, y] = queries[i];
        if (op == 2) {
            mx = max(mx, x);
        }
        else if (!used[x]) {
            ans[x] = max(mx, y);
            used[x] = true;
        }
    }
    
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            ans[i] = max(A[i], mx);
        }
    }
    
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " \n"[i == n];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        solve();
    }
    
    return 0;
}