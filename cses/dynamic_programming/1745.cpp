/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Money Sums

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
    for (auto& x : A) cin >> x;
    int mx_sum = accumulate(A.begin(), A.end(), 0);

    vector<int> ans;
    vector dp(n, vector<int>(mx_sum + 1, -1));
    auto fun = [&](auto&& self, int indx, int sum) -> int {
        if (sum == 0) return 1;
        if (sum < 0 || indx == n) return 0;
        if (dp[indx][sum] != -1) return dp[indx][sum];
        return dp[indx][sum] = max(self(self, indx + 1, sum), self(self, indx + 1, sum - A[indx]));
    };

    for (int i = 1; i <= mx_sum; i++) {
        if (fun(fun, 0, i)) {
            ans.push_back(i);
        }
    }
    
    cout << ans.size() << nl;
    for (auto& x : ans) {
        cout << x << " ";
    }
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