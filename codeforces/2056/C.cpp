/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Palindromic Subsequences

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
    vector<int> ans(n);
    ans[0] = ans[n - 2] = ans[n - 1] = 1;
    for (int i = 1; i < n - 2; i++) {
        ans[i] = i + 1;
    }
    
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i + 1 == n];
    }
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