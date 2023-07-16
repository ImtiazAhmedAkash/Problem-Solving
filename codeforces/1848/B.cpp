/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Vika and the Bridge

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define mod 998244353
#define N 300005
#define deb(x) cerr << #x << " = " << x << nl

void solve() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> a(k + 2);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        a[x].push_back(i);
    }

    int ans = INF;
    for (int i = 1; i <= k; i++) {
        if (a[i].empty()) continue;
        priority_queue<int> pq;
        for (int j = 0; j <= a[i].size(); j++) {
            if (j == 0) {
                pq.push(a[i].front() - 1);
            } else if (j == a[i].size()) {
                pq.push(n - a[i].back());
            } else {
                pq.push(a[i][j] - a[i][j - 1] - 1);
            }
        }
        int maxi = pq.top();
        pq.pop();
        int second_maxi = pq.top();
        int tmp = max(maxi / 2, second_maxi);
        ans = min(ans, tmp);
    }

    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}