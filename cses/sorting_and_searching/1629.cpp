/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Movie Festival

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
    vector<pair<int, int>> A(n);
    for (auto &[x, y] : A) cin >> x >> y;
    sort(A.begin(), A.end(), [&](pair<int, int> x, pair<int, int> y) {
        if (x.second == y.second) return x.first < y.first;
        return x.second < y.second;
    });
    int ans = 0, lst = 0;
    for (auto [x, y] : A) {
        if (lst <= x) {
            ans++;
            lst = y;
        }
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