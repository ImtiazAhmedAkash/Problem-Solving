/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Vika and Her Friends

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define mod 998244353
#define N 300005
#define deb(x) cerr << #x << " = " << x << nl

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    int x, y;
    cin >> x >> y;
    int vika = (x + y) % 2;
    string ans = "YES";
    while (k--) {
        cin >> x >> y;
        if (vika == ((x + y) % 2)) ans = "NO" ;
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