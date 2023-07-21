/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Soft Drinking

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define mod 998244353
#define N 300005
#define deb(x) cerr << #x << " = " << x << nl

void solve() {
    int n, k, l, c, d, p, Nl, np;
    cin >> n >> k >> l >> c >> d >> p >> Nl >> np;
    int drink = k * l;
    int lime = c * d;
    int ans = min({drink / Nl, lime, p / np});
    cout << ans / n << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
    
    return 0;
}