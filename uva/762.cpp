/*  In the Name of ALLAH, the most gracious, the most merciful  */

// We Ship Cheap

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;
bool ok = false;

void solve() {
    int n;
    while (cin >> n) {
        if (ok) cout << nl;
        ok = true;
        vector<int> G[2 * n + 1];
        map<string, int> M;
        map<int, string> ID;
        int indx = 1;
        while (n--) {
            string a, b;
            cin >> a >> b;
            if (M.find(a) == M.end()) {
                ID[indx] = a;
                M[a] = indx++;
            }
            if (M.find(b) == M.end()) {
                ID[indx] = b;
                M[b] = indx++;
            }
            int u = M[a];
            int v = M[b];
            G[u].push_back(v);
            G[v].push_back(u);
        }

        vector<int> par(indx, -1);
        auto bfs = [&](int src, int target) {
            par[src] = 0;
            queue<int> Q;
            Q.push(src);
            while (!Q.empty()) {
                int u = Q.front();
                Q.pop();
                for (auto v : G[u]) {
                    if (par[v] == -1) {
                        par[v] = u;
                        Q.push(v);
                    }
                }
            }
        };

        string a, b;
        cin >> a >> b;
        if (M.find(a) != M.end() && M.find(b) != M.end()) bfs(M[b], M[a]);

        if (par[M[a]] == -1) {
            cout << "No route" << nl;
            continue;
        }
        vector<string> ans;
        for (int v = M[a]; v != 0; v = par[v]) {
            ans.push_back(ID[v]);
        }
        for (int i = 0; i + 1 < ans.size(); i++) {
            cout << ans[i] << " " << ans[i + 1] << nl;
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