/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Hard Compare

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define N 300005
#define deb(x) cerr << #x << " = " << x << nl
const ll mod = 998244353;

void solve() {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    if (b * log(a) > d * log(c)) {
        cout << "YES" << nl;
    } else {
        cout << "NO" << nl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    while (t--) {
        solve();
    }
    
    return 0;
}