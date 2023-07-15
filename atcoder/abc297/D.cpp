/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Count Subtractions

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define mod 998244353
#define N 300005
#define deb(x) cerr << #x << " = " << x << nl

void solve() {
    ll a, b;
    cin >> a >> b;
    
    ll ans = 0;
    while(1) {
        if (a < b) swap(a, b);
        ans += (a / b) - (a % b == 0);
        if (a % b == 0) break;
        a %= b;
    }
    
    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
    
    return 0;
}