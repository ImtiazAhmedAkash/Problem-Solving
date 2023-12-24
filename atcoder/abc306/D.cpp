/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Poisonous Full-Course

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 3e5;

vector<ll> A(N + 5), B(N + 5);
vector<vector<ll>> dp(N + 5, vector<ll>(2, -1));

int n;

ll fun(int indx, int op) {
    if (indx == n + 1) return 0;
    if (~dp[indx][op]) return dp[indx][op];

    if (op == 1 && A[indx] == 1) {
        return dp[indx][op] = fun(indx + 1, op);
    }
    return dp[indx][op] = max(B[indx] + fun(indx + 1, A[indx]), fun(indx + 1, op));
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> A[i] >> B[i];
    }
    ll ans = fun(0, 0);
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