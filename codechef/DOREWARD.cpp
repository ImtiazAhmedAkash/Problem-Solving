/*  In the Name of ALLAH, the most gracious, the most merciful  */

// DOREWARD - Donation Rewards

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define mod 998244353
#define N 300005
#define deb(x) cerr << #x << " = " << x << nl

void solve() {
    int n;
    cin >> n;
    string ans = "SILVER";
    if (n > 6) ans = "GOLD";
    else if (n < 4) ans = "BRONZE";
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