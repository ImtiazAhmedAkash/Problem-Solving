/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Bertown Subway

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 1e5 + 5;

vector<int> G[N];
vector<bool> used(N, false);
int node = 0;

void dfs(int u) {
    node++;
    used[u] = true;
    for (auto v : G[u]) {
        if (!used[v]) {
            dfs(v);
        }
    }
}

void solve() {
    int n;
    cin >> n;
    for (int u = 1; u <= n; u++) {
        int v;
        cin >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    vector<int> A;
    for (int i = 1; i <= n; i++) {
        node = 0;
        if (!used[i]) {
            dfs(i);
            A.push_back(node);
        }
    }
    sort(A.begin(), A.end());
    if (A.size() > 1) {
        int x = A.back();
        A.pop_back();
        A.back() += x;
    }
    ll ans = 0;
    for (auto x : A) {
        ans += 1LL * x * x;
    }
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