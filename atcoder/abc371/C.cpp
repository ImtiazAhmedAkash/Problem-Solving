/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Make Isomorphic

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
    vector G(n + 1, vector<int>(n + 1));
    auto H = G, A = G;

    int mg;
    cin >> mg;
    for (int i = 0; i < mg; i++) {
        int u, v;
        cin >> u >> v;
        G[u][v] = G[v][u] = 1;
    }

    int mh;
    cin >> mh;
    for (int i = 0; i < mh; i++) {
        int u, v;
        cin >> u >> v;
        H[u][v] = H[v][u] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            cin >> A[i][j];
        }
    }

    vector<int> order(n + 1);
    iota(order.begin(), order.end(), 0);

    ll ans = INF;
    do {
        ll cur = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (G[i][j] != H[order[i]][order[j]]) {
                    int x = min(order[i], order[j]);
                    int y = max(order[i], order[j]);
                    cur += A[x][y];
                }
            }
        }
        ans = min(ans, cur);
    } while (next_permutation(order.begin() + 1, order.end()));

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