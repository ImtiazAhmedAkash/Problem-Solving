/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Buying Shovels

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define mod 998244353
#define N 300005
#define deb(x) cerr << #x << " = " << x << nl

void solve() {
    int shovel, package;
    cin >> shovel >> package;
    int ans = INF;
    for (int i = 1; i * i <= shovel; i++) {
        if (shovel % i == 0) {
            if (i <= package) ans = min(ans, shovel / i);
            if ((shovel / i) <= package) ans = min(ans, i);
        }
    }
    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}