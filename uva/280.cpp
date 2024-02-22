/*  In the Name of ALLAH, the most gracious, the most merciful  */

// 280 - Vertex

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;

void solve() {
    int n;
    while (cin >> n && n) {
        vector<vector<int>> G(n + 1, vector<int>());
        int m;
        while (cin >> m && m) {
            int k;
            while (cin >> k && k) {
                G[m].push_back(k);
            }
        }
        
        auto bfs = [&](int src) -> void {
            vector<bool> used(n + 1, false);
            vector<int> ans;
            
            queue<int> Q;
            Q.push(src);
            while (!Q.empty()) {
                int u = Q.front();
                Q.pop();
                for (auto v : G[u]) {
                    if (!used[v]) {
                        used[v] = true;
                        Q.push(v);
                    }
                }
            }
            
            for (int i = 1; i <= n; i++) {
                if (!used[i]) {
                    ans.push_back(i);
                }
            }
            cout << ans.size();
            for (auto x : ans) {
                cout << ' ' << x;
            }
            cout << nl;
        };
        
        int q;
        cin >> q;
        while (q--) {
            int src;
            cin >> src;
            bfs(src);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    solve();
    
    return 0;
}