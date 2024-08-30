/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Light Switches

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
    vector<int> A(n);
    for (auto &x : A) cin >> x;

    int l1 = *max_element(A.begin(), A.end());
    int r1 = l1 + k - 1;

    for (int i = 0; i < n; i++) {
        int l2 = A[i] + 2 * k * ((r1 - A[i]) / (2 * k));
        int r2 = l2 + k - 1;
        l1 = max(l1, l2);
        r1 = min(r1, r2);
        if (l1 > r1) {
            cout << -1 << nl;
            return;
        }
    }
    cout << l1 << nl;
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