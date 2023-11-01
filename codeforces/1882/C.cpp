/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Card Game

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
    int n;
    cin >> n;
    vector<ll> A(n);
    for (auto &x : A) cin >> x;
    
    ll ans = 0;
    for (int i = 2; i < n; i++) {
        if (A[i] > 0) ans += A[i];
    }
    if (n == 1) ans += max(0LL, A[0]);
    else ans += max({0LL, A[0], A[0] + A[1]});
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