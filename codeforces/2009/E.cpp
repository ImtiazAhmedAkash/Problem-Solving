/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Klee's SUPER DUPER LARGE Array!!!

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
    ll n, k;
    cin >> n >> k;

    auto find_sum = [&](ll x) -> ll {
        return (k + k + x - 1) * x / 2;
    };

    ll sum = find_sum(n);
    ll need = sum / 2;

    ll L = 1, R = n;
    while (L < R) {
        ll M = L + (R - L + 1) / 2;
        if (find_sum(M) <= need) {
            L = M;
        } else {
            R = M - 1;
        }
    }

    ll ans = INF;
    ll x1 = find_sum(R);
    ans = min(ans, abs(x1 - (sum - x1)));
    ll x2 = find_sum(R + 1);
    ans = min(ans, abs(x2 - (sum - x2)));
    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        solve();
    }

    return 0;
}