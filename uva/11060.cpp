/*  In the Name of ALLAH, the most gracious, the most merciful  */

// 11060 - Beverages

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
    int n, T = 1;
    while (cin >> n) {
        vector<vector<int>> G(n, vector<int>());
        map<string, int> M;
        map<int, string> P;

        int id = 0;
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            P[id] = s;
            M[s] = id++;
        }

        int m;
        cin >> m;
        vector<int> indegree(n, 0);
        while (m--) {
            string s, t;
            cin >> s >> t;
            int u = M[s];
            int v = M[t];
            G[u].push_back(v);
            indegree[v]++;
        }

        set<int> st;
        for (int u = 0; u < n; u++) {
            if (indegree[u] == 0) {
                st.insert(u);
            }
        }

        vector<int> ans;
        auto topological_sort = [&]() -> void {
            while (!st.empty()) {
                auto u = *st.begin();
                st.erase(st.begin());
                ans.push_back(u);
                for (auto v : G[u]) {
                    indegree[v]--;
                    if (indegree[v] == 0) {
                        st.insert(v);
                    }
                }
            }
        };

        topological_sort();

        cout << "Case #" << T++ << ": Dilbert should drink beverages in this order: ";
        for (int i = 0; i < ans.size(); i++) {
            cout << P[ans[i]] << " ."[i + 1 == ans.size()];
        }
        cout << nl << nl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}