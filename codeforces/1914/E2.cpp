/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Game with Marbles (Hard Version)

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
    for (auto &z : A) cin >> z;
    for (auto &z : B) cin >> z;
    vector<pair<ll, ll>> C(n);
    for (int i = 0; i < n; i++) {
        C[i] = {A[i] + B[i], i};
    }
    sort(C.begin(), C.end(), greater());
    ll alice = 0, bob = 0;
    for (int i = 0; i < n; i++) {
        if (i & 1) bob += B[C[i].second] - 1;
        else alice += A[C[i].second] - 1;
    }
    cout << alice - bob << nl;
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