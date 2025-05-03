/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// C - 403 Forbidden

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
    int n, m, q;
    cin >> n >> m >> q;
    vector<set<int>> A(n + 1);
    vector<bool> granted(n + 1, false);
    
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int x, y;
            cin >> x >> y;
            A[x].insert(y);
        }
        else if (op == 2) {
            int x;
            cin >> x;
            granted[x] = true;
        }
        else {
            int x, y;
            cin >> x >> y;
            cout << ((granted[x] || A[x].find(y) != A[x].end()) ? "Yes" : "No") << nl;
        }
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