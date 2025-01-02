/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Consecutive Subsequence

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
    vector<int> A(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    
    map<int, int> dp;
    int mx = 0;
    int last = -1;
    for (int i = 1; i <= n; i++) {
        dp[A[i]] = dp[A[i] - 1] + 1;
        if (mx < dp[A[i]]) {
            mx = dp[A[i]];
            last = A[i];
        }
    }
    
    vector<int> ans;
    for (int i = n; i > 0; i--) {
        if (A[i] == last) {
            ans.push_back(i);
            last--;
        }
    }
    
    reverse(ans.begin(), ans.end());
    cout << ans.size() << nl;
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << nl;
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