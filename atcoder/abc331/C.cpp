/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Sum of Numbers Greater Than Me

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
    vector<ll> A(n + 1);
    for (int i = 1; i <= n; i++) cin >> A[i];
    auto B = A;
    sort(B.begin(), B.end());
    vector<ll> pref(n + 1);
    partial_sum(B.begin(), B.end(), pref.begin());
    for (int i = 1; i <= n; i++) {
        int l = upper_bound(B.begin(), B.end(), A[i]) - B.begin();
        cout << pref[n] - pref[l - 1] << ' ';
    }
    cout << nl;
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