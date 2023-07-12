/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Very Easy Task

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define mod 998244353
#define N 300005
#define deb(x) cerr << #x << " = " << x << nl

void solve() {
    ll n, x, y;
    cin >> n >> x >> y;
    
    auto check = [&] (ll mid) {
        return (mid / x) + (mid / y) >= n - 1;
    };
    
    ll lo = -1, hi = 1e18;
    while (lo + 1 < hi) {
        ll mid = (lo + hi) / 2;
        if (check(mid)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    cout << hi + min(x, y) << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
    
    return 0;
}