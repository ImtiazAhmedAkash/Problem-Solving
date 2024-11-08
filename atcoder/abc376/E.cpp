/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Max × Sum

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
    vector<pair<int, int>> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i].first;
    }
    for (int i = 0; i < n; i++) {
        cin >> A[i].second;
    }

    sort(A.begin(), A.end());

    priority_queue<int> pq;
    ll sum = 0;
    ll ans = INF;
    for (int i = 0; i < n; i++) {
        sum += A[i].second;
        pq.push(A[i].second);
        if (pq.size() == k) {
            ans = min(ans, 1LL * A[i].first * sum);
            sum -= pq.top();
            pq.pop();
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