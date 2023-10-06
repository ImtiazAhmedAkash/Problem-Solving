/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Modulo Equality

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 2e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> A(n), B(n);
    for (auto &x : A) cin >> x;
    for (auto &x : B) cin >> x;
    queue<int> q;
    for (int i = 0; i < n; i++) {
        int cur = (B[0] - A[i] + m) % m;
        q.push(cur);
    }
    sort(B.begin(), B.end());
    int ans = inf;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        vector<int> C(n);
        for (int i = 0; i < n; i++) {
            C[i] = (A[i] + x) % m;
        }
        sort(C.begin(), C.end());
        if (B == C) {
            ans = min(ans, x);
        }
        rotate(A.begin(), A.begin() + 1, A.end());
    }
    cout << ans << nl;
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