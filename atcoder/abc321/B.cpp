/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Cutoff

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
    int n, k;
    cin >> n >> k;
    vector<ll> A(n - 1);
    for (auto &x : A) cin >> x;
    
    auto check = [&] (ll mid) {
        auto B = A;
        B.push_back(mid);
        sort(B.begin(), B.end());
        ll cur = 0;
        for (int i = 1; i < n - 1; i++) cur += B[i];
        return cur >= k;
    };
    
    ll L = 0, R = inf;
    while (L < R) {
        ll M = L + (R - L) / 2;
        if (check(M)) R = M;
        else L = M + 1;
    }
    if (L > 100) L = -1;
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