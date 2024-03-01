/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Foreign Exchange

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
    for (auto& x : A) cin >> x;
    for (int i = 0; i + 1 < n; i++) {
        ll a, b;
        cin >> a >> b;
        A[i + 1] += b * (A[i] / a);
    }
    cout << A.back() << nl;
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