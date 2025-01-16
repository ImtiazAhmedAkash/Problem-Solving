/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Separated Lunch

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 2e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;

void solve() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (auto &x : A) cin >> x;
    
    int ans = inf;
    for (int mask = 1; mask < (1 << n); mask++) {
        int zero = 0;
        int one = 0;
        for (int bit = 0; bit < n; bit++) {
            if (mask & (1 << bit)) {
                one += A[bit];
            } else {
                zero += A[bit];
            }
        }
        ans = min(ans, max(zero, one));
    }
    
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