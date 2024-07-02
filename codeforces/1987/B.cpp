/*  In the Name of ALLAH, the most gracious, the most merciful  */

// K-Sort

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
    for (auto& x : A) cin >> x;
    vector<int> B;
    for (int i = 0; i + 1 < n; i++) {
        if (A[i] > A[i + 1]) {
            B.push_back(A[i] - A[i + 1]);
            A[i + 1] = A[i];
        }
    }
    sort(B.begin(), B.end());
    ll ans = 0;
    ll op = 0;
    int m = B.size();
    for (int i = 0; i < m; i++) {
        ans += 1LL * (B[i] - op) * (m - i + 1);
        op = B[i];
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