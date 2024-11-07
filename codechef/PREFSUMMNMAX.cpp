/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// PREFSUMMNMAX - Prefix Suffix Min Max

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 2e6;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;

void solve() {
    int n;
    cin >> n;
    vector<int> B(n);
    for (auto &x : B) cin >> x;

    vector<int> ans(n);
    ans.front() = inf;
    ll sum = inf;
    int mx = inf;
    for (int i = 1; i < n; i++) {
        ans[i] = mx + B[i] - sum;
        sum += ans[i];
        mx = max(mx, ans[i]);
    }

    for (auto &x : ans) {
        cout << x << " ";
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