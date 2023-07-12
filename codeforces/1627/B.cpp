/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Not Sitting

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define mod 998244353
#define N 300005
#define deb(x) cerr << #x << " = " << x << nl

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> a = {{1, 1}, {1, m}, {n, 1}, {n, m}};
    vector<int> res;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int ans = 0, tmp;
            for (auto [x, y] : a) {
                tmp = abs(x - i) + abs(y - j);
                ans = max(ans, tmp);
            }
            res.push_back(ans);
        }
    }
    sort(res.begin(), res.end());
    for (auto x : res) cout << x << " ";
    cout << nl;
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