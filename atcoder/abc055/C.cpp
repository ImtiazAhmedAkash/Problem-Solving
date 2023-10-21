/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Scc Puzzle

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;

void solve() {
    ll n, m;
    cin >> n >> m;
    
    auto check = [&](ll mid) {
        ll s = mid, c = mid * 2;
        if (s > n) {
            ll x = (s - n) * 2;
            c += x;
        }
        return c <= m;
    };
    
    ll L = -1, R = INF;
    while (L < R) {
        ll M = L + (R - L + 1) / 2;
        if (check(M)) L = M;
        else R = M - 1;
    }
    cout << R << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    for (int t = 1; t <= T; t++) {
        solve();
    }
    
    return 0;
}