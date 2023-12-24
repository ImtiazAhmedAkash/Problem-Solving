/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Reindeer and Sleigh

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
    int n, q;
    cin >> n >> q;
    vector<ll> A(n);
    for (auto &x : A) cin >> x;
    sort(A.begin(), A.end());
    vector<ll> pref(n + 1);
    partial_sum(A.begin(), A.end(), pref.begin() + 1);
    while (q--) {
        ll x;
        cin >> x;
        cout << upper_bound(pref.begin(), pref.end(), x) - pref.begin() - 1 << nl;
    }
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