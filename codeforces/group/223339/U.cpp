/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Knapsack

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;

int fun(int indx, int rem, vector<int>& w, vector<int>& v) {
    if (rem < 0) return -inf;
    if (indx == w.size()) return 0;
    return max(fun(indx + 1, rem, w, v), v[indx] + fun(indx + 1, rem - w[indx], w, v));
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> w(n), v(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i] >> v[i];
    }

    cout << fun(0, k, w, v) << nl;
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