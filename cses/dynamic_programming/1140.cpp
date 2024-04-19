/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Projects

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5;

void solve() {
    int n;
    cin >> n;
    map<int, int> M;
    vector<int> A(n), B(n), reward(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i] >> B[i] >> reward[i];
        M[A[i]] = 0;
        M[B[i]] = 0;
    }
    // Compress the number of days
    int id = 1;
    for (auto& [x, y] : M) {
        y = id++;
    }

    vector ends(id, vector<pair<int, int>>());
    for (int i = 0; i < n; i++) {
        B[i] = M[B[i]];
        A[i] = M[A[i]];
        ends[B[i]].push_back({A[i], reward[i]});
    }
    vector<ll> dp(id);
    // dp[i] = maximum amount of money that can be earned at day[i]
    for (int i = 1; i < id; i++) {
        dp[i] = dp[i - 1];
        for (auto vec : ends[i]) {
            int x = vec.first;
            int y = vec.second;
            dp[i] = max(dp[i], dp[x - 1] + y);
        }
    }
    cout << dp.back() << nl;
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