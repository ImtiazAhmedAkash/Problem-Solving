/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Word Transformation

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
    vector<string> A;
    map<string, int> M;
    int indx = 0;
    string s;
    while (cin >> s && s != "*") {
        A.push_back(s);
        M[s] = indx++;
    }
    
    auto check = [&](string a, string b) {
        if (a.size() != b.size()) return false;
        int diff = 0;
        for (int i = 0; i < a.size(); i++) {
            diff += (a[i] != b[i]);
        }
        return diff == 1;
    };
    
    vector<int> G[indx];
    for (int i = 0; i < indx; i++) {
        for (int j = 0; j < indx; j++) {
            if (i == j) continue;
            if(check(A[i], A[j])) {
                int u = M[A[i]];
                int v = M[A[j]];
                G[u].push_back(v);
                G[v].push_back(u);
            }
        }
    }
    
    auto bfs = [&](int src, int target) {
        vector<int> dist(indx, -1);
        dist[src] = 0;
        queue<int> Q;
        Q.push(src);
        while (!Q.empty()) {
            int u = Q.front();
            Q.pop();
            for (auto v : G[u]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    Q.push(v);
                }
            }
        }
        return dist[target];
    };
    
    cin.ignore();
    string line;
    while (getline(cin, line) && !line.empty()) {
        stringstream ss(line);
        string a, b;
        ss >> a >> b;
        int ans = bfs(M[a], M[b]);
        cout << a << " " << b << " " << ans << nl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        solve();
        if (t != T) cout << nl;
    }
    
    return 0;
}