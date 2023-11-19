/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Yarik and Array

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
    vector<int> A(n);
    for (auto &x : A) {
        cin >> x;
    }
    int ans = -inf, cur = 0, parity = -1;
    for (int i = 0; i < n; i++) {
        if ((abs(A[i]) % 2) == parity) {
            cur = A[i];
        } else {
            cur += A[i];
        }
        parity = abs(A[i]) % 2;
        ans = max(ans, cur);
        if (cur <= 0) {
            cur = 0;
            parity = -1;
        }
    }
    cout << ans << nl;
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