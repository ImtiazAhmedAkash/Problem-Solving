/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Deja Vu

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
    vector<ll> A(n), Q(q);
    for (auto &x : A) cin >> x;
    for (auto &x : Q) cin >> x;
    vector<bool> used(31, false);
    for (int i = 0; i < q; i++) {
        if (used[Q[i]]) continue;
        used[Q[i]] = true;
        ll cur = 1LL << Q[i];
        ll add = 1LL << (Q[i] - 1);
        for (int j = 0; j < n; j++) {
            if (A[j] % cur == 0) {
                A[j] += add;
            }
        }
    }
    for (auto x : A) cout << x << " ";
    cout << nl;
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