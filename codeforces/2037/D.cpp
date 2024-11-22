/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Sharky Surfing

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
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int, int>> A(n);
    for (auto &[x, y] : A) cin >> x >> y;
    vector<pair<int, int>> B(m);
    for (auto &[x, y] : B) cin >> x >> y;

    priority_queue<int> pq;
    ll cur = 1;
    int ans = 0;

    for (int i = 0, j = 0; i < n; i++) {
        while (j < m && B[j].first < A[i].first) {
            pq.push(B[j].second);
            j++;
        }

        while (!pq.empty() && A[i].first - 1 + cur <= A[i].second) {
            int x = pq.top();
            pq.pop();
            cur += x;
            ans++;
        }

        if (A[i].first - 1 + cur <= A[i].second) {
            cout << -1 << nl;
            return;
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