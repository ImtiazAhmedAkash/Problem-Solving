/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Not Incomplete

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;

void solve() {
    int X, Y, Z, N;
    cin >> X >> Y >> Z >> N;
    int need = ((X * Y * 60) + 99) / 100;
    int rem = (X - Z) * Y;
    if (N + rem < need) {
        cout << "No" << nl;
        return;
    }
    cout << "Yes" << nl;
    rem = min(rem, max(0, need - N));
    vector<int> ans(X - Z);
    for (int i = 0; i < ans.size(); i++) {
        ans[i] = min(rem, Y);
        rem -= min(rem, Y);
    }
    reverse(ans.begin(), ans.end());
    for (auto x : ans) cout << x << " ";
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