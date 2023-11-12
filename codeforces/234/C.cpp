/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Weather

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
    vector<int> pos(n + 1), neg(n + 1);
    int zero = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (x == 0) zero++;
        else if (x > 0) pos[i] = 1;
        else neg[i] = 1;
    } 
    partial_sum(pos.begin(), pos.end(), pos.begin());
    partial_sum(neg.rbegin(), neg.rend(), neg.rbegin());
    int ans = inf;
    for (int i = 1; i < n; i++) {
        int cur = pos[i] + neg[i + 1] + zero;
        ans = min(ans, cur);
    }
    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int T = 1;
    for (int t = 1; t <= T; t++) {
        solve();
    }
    
    return 0;
}