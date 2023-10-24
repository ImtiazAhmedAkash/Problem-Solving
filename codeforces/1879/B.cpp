/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Chips on the Board

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
    vector<ll> A(n), B(n);
    for (auto &x : A) cin >> x;
    for (auto &x : B) cin >> x;
    ll mina = *min_element(A.begin(), A.end());
    ll minb = *min_element(B.begin(), B.end());
    ll x = accumulate(A.begin(), A.end(), 0LL);
    ll y = accumulate(B.begin(), B.end(), 0LL);
    cout << min(mina * n + y, minb * n + x) << nl;
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