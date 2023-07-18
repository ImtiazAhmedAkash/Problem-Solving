/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Chat Ban

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define mod 998244353
#define N 300005
#define deb(x) cerr << #x << " = " << x << nl

void solve() {
    ll k, x;
    cin >> k >> x;
    
    auto check = [&] (ll mid) {
        ll msg = min(mid, k);
        ll emo = msg * (msg + 1) / 2;
        if (mid > k) {
            ll excluded = k - 1 - (mid - k);
            emo += (((k - 1) * k / 2) - (excluded * (excluded + 1) / 2));
        }
        return emo < x;
    };
    
    ll L = 1, R = (2 * k) - 1;
    while (L < R) {
        ll M = L + (R - L) / 2;
        if (check(M)) {
            L = M + 1;
        } else {
            R = M;
        }
    }
    cout << L << nl;
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