/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Multiplication Table

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define mod 998244353
#define N 300005
#define deb(x) cerr << #x << " = " << x << nl

void solve() {
    ll n, m, k;
    cin >> n >> m >> k;
    ll L = 1, R = 1e18;
    
    auto check = [&] (ll mid) {
        ll cnt = 0;
        for (int i = 1; i <= n; i++) {
            cnt += min(m, mid / i);
            if (cnt >= k) return false;
        }
        return true;
    };
    
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

    solve();
    
    return 0;
}