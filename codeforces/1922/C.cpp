/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Closest Cities

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
    vector<int> A(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    vector<ll> pref(n + 1);
    pref[2] = 1;
    for (int i = 2; i < n; i++) {
        pref[i + 1] = (A[i + 1] - A[i] < A[i] - A[i - 1] ? 1 : A[i + 1] - A[i]);
        pref[i + 1] += pref[i];
    }
    vector<ll> suff(n + 2);
    suff[n - 1] = 1;
    for (int i = n - 1; i > 1; i--) {
        suff[i - 1] = (A[i] - A[i - 1] < A[i + 1] - A[i] ? 1 : A[i] - A[i - 1]);
        suff[i - 1] += suff[i];
    }
    int q;
    cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y;
        cout << (x < y ? pref[y] - pref[x] : suff[y] - suff[x]) << nl;
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