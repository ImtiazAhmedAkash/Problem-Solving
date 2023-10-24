/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Dances (Hard Version)

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
    int n, m;
    cin >> n >> m;
    vector<int> A(n), B(n);
    A[0] = 1;
    for (int i = 1; i < n; i++) {
        cin >> A[i];
    }
    for (auto &x : B) {
        cin >> x;
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    set<int> S;
    int op = 0;
    for (int i = 0, j = 1; i < n; i++) {
        if (j < n && A[j] < B[i]) {
            j++;
        } else {
            S.insert(B[i]);
        }
        op = n - j;
    }
    int match = *(S.rbegin()) - 1;
    ll ans = 1LL * op * min(m, match) + 1LL * (m - min(m, match)) * (op + 1);
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