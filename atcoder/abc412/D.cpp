/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// 	D - Make 2-Regular Graph

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
    vector G(n + 1, vector<int>(n + 1));
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        G[u][v] = G[v][u] = 1;
    }
    
    vector<int> order(n);
    iota(order.begin(), order.end(), 1);
    
    vector H(n + 1, vector<int>(n + 1));
    
    auto reset_graph = [&]() -> void {
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                H[i][j] = 0;
            }
        }
    };
    
    auto build_graph = [&](int l, int r) -> void {
        vector<int> A;
        for (int i = l; i <= r; i++) {
            A.push_back(order[i]);
        }
        int u = A.front();
        int v = A.back();
        H[u][v] = H[v][u] = 1;
        for (int i = 0; i + 1 < A.size(); i++) {
            u = A[i];
            v = A[i + 1];
            H[u][v] = H[v][u] = 1;
        }
    };
    
    auto check_diff = [&]() -> int {
        int cur = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                cur += (G[i][j] != H[i][j]);
            }
        }
        return cur;
    };
    
    int ans = inf;
    do {
        reset_graph();
        build_graph(0, n - 1);
        ans = min(ans, check_diff());
        
        if (n == 6) {
            reset_graph();
            build_graph(0, 2);
            build_graph(3, 5);
            ans = min(ans, check_diff());
        }
        
        if (n == 7) {
            reset_graph();
            build_graph(0, 2);
            build_graph(3, 6);
            ans = min(ans, check_diff());
        }
        
        if (n == 8) {
            reset_graph();
            build_graph(0, 2);
            build_graph(3, 7);
            ans = min(ans, check_diff());
            
            reset_graph();
            build_graph(0, 3);
            build_graph(4, 7);
            ans = min(ans, check_diff());
        }
    } while (next_permutation(order.begin(), order.end()));
    
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