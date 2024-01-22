/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Valeriy and Deque

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
    vector<int> A(n);
    for (auto &x : A) cin >> x;
    int mx = A.front();
    vector<pair<int, int>> ans(n);
    vector<int> rem(n - 1);
    for (int i = 1; i < n; i++) {
        ans[i] = {mx, A[i]};
        rem[i - 1] = min(mx, A[i]);
        mx = max(mx, A[i]);
    }
    while (q--) {
        ll m;
        cin >> m;
        if (m < n) {
            cout << ans[m].first << " " << ans[m].second << nl;
        } else {
            cout << mx << " " << rem[(m - n) % (n - 1)] << nl;
        }
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