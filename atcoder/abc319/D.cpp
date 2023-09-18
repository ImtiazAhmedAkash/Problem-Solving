/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Minimum Width

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = (1 << 30);
const ll INF = (1LL << 62);
const int mod = 998244353;
const int N = 2e5 + 5;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (auto &x : a) cin >> x;
    
    auto check = [&] (ll mid) {
        ll line = 1, cur = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] > mid) return false;
            if (cur + a[i] <= mid) {
                cur += a[i];
            } else {
                line++;
                cur = a[i];
            }
            if (i + 1 != n) cur++;
        }
        return line <= m;
    };
    
    ll L = 0, R = INF;
    while (L < R) {
        ll M = L + (R - L) / 2;
        if (check(M)) R = M;
        else L = M + 1;
    }
    cout << L << nl;
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