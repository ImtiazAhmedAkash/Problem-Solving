/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// B - The Last Bit of Us

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

template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<>>;

void solve() {
    int n;
    cin >> n;
    vector<int> A(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    vector<set<int>> G(n + 1);
    vector<int> degree(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        G[u].insert(v);
        G[v].insert(u);
        degree[u]++, degree[v]++;
    }

    min_heap<pair<int, int>> pq;
    for (int i = 1; i <= n; i++) {
        if (degree[i] == 1) {
            pq.push({A[i], i});
        }
    }

    int ans = 0;
    while (!pq.empty()) {
        auto [_, u] = pq.top();
        pq.pop();

        if (G[u].empty()) continue;

        int v = *G[u].begin();
        if (A[u]) {
            A[u] ^= 1;
            A[v] ^= 1;
            ans++;
        }
        G[u].erase(v);
        G[v].erase(u);
        degree[u]--;
        degree[v]--;
        if (degree[v] == 1) {
            pq.push({A[v], v});
        }
    }

    for (int i = 1; i <= n; i++) {
        if (A[i]) {
            cout << -1 << nl;
            return;
        }
    }

    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        solve();
    }

    return 0;
}