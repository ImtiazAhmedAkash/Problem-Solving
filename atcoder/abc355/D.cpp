/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Intersecting Intervals

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
    int n;
    cin >> n;
    vector<pair<int, int>> A(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        A[i] = {x, y};
    }
    sort(A.begin(), A.end());
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int L = lower_bound(A.begin(), A.end(), make_pair(A[i].first, A[i].second)) - A.begin();
        L = max(i, L);
        int R = upper_bound(A.begin(), A.end(), make_pair(A[i].second, inf)) - A.begin();
        ans += R - L - 1;
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