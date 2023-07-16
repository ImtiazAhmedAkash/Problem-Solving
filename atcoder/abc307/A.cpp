/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Weekly Records

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
    while(n--) {
        ll x;
        ll ans = 0;
        for (int i = 0; i < 7; i++) {
            cin >> x;
            ans += x;
        }
        cout << ans << " ";
    }
    cout << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
    
    return 0;
}