/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Checkpoints

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
    vector<pair<int, int>> A(n), B(m);
    for (int i = 0; i < n; i++) {
        cin >> A[i].first >> A[i].second;
    }
    for (int i = 0; i < m; i++) {
        cin >> B[i].first >> B[i].second;
    }
    for (int i = 0; i < n; i++) {
        int ans = -1, mini = inf;
        for (int j = 0; j < m; j++) {
            int cur = abs(A[i].first - B[j].first) + abs(A[i].second - B[j].second);
            if (cur < mini) {
                mini = cur;
                ans = j + 1;
            }
        }
        cout << ans << nl;
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