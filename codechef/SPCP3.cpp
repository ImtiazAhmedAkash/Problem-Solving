/*  In the Name of ALLAH, the most gracious, the most merciful  */

// SPCP3 - Marbles

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
    int a, b;
    cin >> a >> b;
    int ans = inf, sum = a + b;
    for (int i = 1; i < sum; i++) {
        if (i % (sum - i) == 0) {
            ans = min(ans, abs(a - i));
        }
    }
    cout << ans << nl;
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