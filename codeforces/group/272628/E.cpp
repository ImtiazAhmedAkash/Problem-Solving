/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Game

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 1e5;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> A(n);
    for (auto &x : A) cin >> x;
    while (q--) {
        int x;
        cin >> x;
        auto it = upper_bound(A.begin(), A.end(), x);
        cout << (it == A.end() ? -1 : *it) << nl;
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