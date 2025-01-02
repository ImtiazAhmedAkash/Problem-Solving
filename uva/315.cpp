/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// 315 - Network

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
        cin.ignore();
        vector<vector<int>> G(n + 1, vector<int>());
        
        string line;
        while(true) {
            getline(cin, line);
            stringstream ss(line);
            vector<int> A;
            int x;
            while (ss >> x) {
                A.push_back(x);
            }
            if (A.front() == 0) break;
            for (int i = 1; i < A.size(); i++) {
                G[A.front()].push_back(A[i]);
                G[A[i]].push_back(A.front());
            }
        }
        
        set<int> st;
        vector<int> dist(n + 1), low(n + 1);
        int timer = 0;
        function<void(int, int)> find_articulation_point = [&](int u, int par = -1) {
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
        
        find_articulation_point(1, -1);
        
        cout << st.size() << nl;
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