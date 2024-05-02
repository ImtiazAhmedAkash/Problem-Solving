/*  In the Name of ALLAH, the most gracious, the most merciful  */

// FINDPERM343 - Find Permutation

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
    vector<int> A(2 * n);
    for (auto &x : A) cin >> x;
    vector G(n + 1, vector<int>());
    for (int i = 0; i < 2 * n; i++) {
        G[A[i]].push_back(i);
    }
    vector<pair<int, int>> ans(n + 1);
    for (int i = 1; i <= n; i++) {
        ans[i] = {G[i].back() - G[i].front() - 1, i};
    }
    sort(ans.begin(), ans.end(), greater());
    for (auto [x, y] : ans) {
        if (y == 0) continue;
        cout << y << " ";
    }
    cout << nl;
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