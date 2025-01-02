/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// 10199 - Tourist Guide

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
    int cs = 0;
    while (cin >> n && n) {
        if (cs) cout << nl;
        
        map<string, int> id;
        map<int, string> name;
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            name[id.size()] = s;
            id[s] = id.size();
        }
        
        vector<vector<int>> G(n + 1, vector<int>());
        int m;
        cin >> m;
        for (int i = 0; i < m; i++) {
            string s, t;
            cin >> s >> t;
            int u = id[s];
            int v = id[t];
            G[u].push_back(v);
            G[v].push_back(u);
        }
        
        set<int> st;
        vector<int> dist(n + 1), low(n + 1);
        int timer = 0;
        function<void(int, int)> find_articulation_point = [&](int u, int par) {
            dist[u] = low[u] = ++timer;
            int child = 0;
            for (auto &v : G[u]) {
                if (v == par) continue;
                if (!dist[v]) {
                    child++;
                    find_articulation_point(v, u);
                    low[u] = min(low[u], low[v]);
                    if (par != -1 && dist[u] <= low[v]) {
                        st.insert(u);
                    }
                } else {
                    low[u] = min(low[u], dist[v]);
                }
            }
            if (par == -1 && child > 1) {
                st.insert(u);
            }
        };
        
        for (int i = 0; i < n; i++) {
            if (!dist[i]) {
                find_articulation_point(i, -1);
            }
        }
        
        vector<string> ans;
        for (auto &x : st) {
            ans.push_back(name[x]);
        }
        sort(ans.begin(), ans.end());
        
        cout << "City map #" << ++cs << ": " << ans.size() << " camera(s) found" << nl;
        for (auto &x : ans) {
            cout << x << nl;
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