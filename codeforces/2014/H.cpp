/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Robin Hood Archery

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> A(n + 1);
    map<int, ll> M;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        M[A[i]] = rng();
    }

    vector<ll> pref(n + 1);
    for (int i = 1; i <= n; i++) {
        pref[i] = (pref[i - 1] ^ M[A[i]]);
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << ((pref[r] ^ pref[l - 1]) == 0 ? "YES" : "NO") << nl;
    }
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