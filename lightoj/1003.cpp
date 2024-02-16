/*  In the Name of ALLAH, the most gracious, the most merciful  */

// 1003 - Drunk

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
    cin >> n;
    map<string, int> M;
    vector G(2 * n, vector<int>());
    vector<int> indegree(2 * n, 0);
    int id = 0;
    for (int i = 0; i < n; i++) {
        string a, b;
        cin >> a >> b;
        if (M.find(a) == M.end()) {
            M[a] = id++;
        }
        if (M.find(b) == M.end()) {
            M[b] = id++;
        }
        int u = M[a], v = M[b];
        G[u].push_back(v);
        indegree[v]++;
    }

    queue<int> Q;
    for (int i = 0; i < 2 * n; i++) {
        if (indegree[i] == 0) {
            Q.push(i);
        }
    }

    auto topological_sort = [&]() -> bool {
        int cnt = 0;
        while (!Q.empty()) {
            int u = Q.front();
            Q.pop();
            cnt++;
            for (auto v : G[u]) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    Q.push(v);
                }
            }
        }
        return cnt == 2 * n;
    };

    cout << (topological_sort() ? "Yes" : "No") << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "Case " << t << ": ";
        solve();
    }

    return 0;
}