/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Step Up Robot

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 1e5 + 5;

void solve() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (auto &x : A) cin >> x;
    int m;
    cin >> m;
    vector<bool> used(N);
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        used[x] = 1;
    }
    int target;
    cin >> target;

    auto bfs = [&](int src) {
        queue<int> Q;
        Q.push(src);
        used[src] = true;
        while (!Q.empty()) {
            int u = Q.front();
            Q.pop();
            for (auto x : A) {
                int v = u + x;
                if (v > target || used[v]) continue;
                used[v] = true;
                Q.push(v);
            }
        }
    };

    bfs(0);
    cout << (used[target] ? "Yes" : "No") << nl;
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