/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Equalizing by Division (hard version)

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
    vector<int> A(n), B[N];
    for (auto &x : A) {
        cin >> x;
        B[x].push_back(0);
    }
    for (auto x : A) {
        int cnt = 0;
        while (x / 2 > 0) {
            cnt++;
            x = x >> 1;
            B[x].push_back(cnt);
        }
    }
    int ans = inf;
    for (int i = 0; i < N; i++) {
        if (B[i].size() >= k) {
            sort(B[i].begin(), B[i].end());
            int cur = accumulate(B[i].begin(), B[i].begin() + k, 0);
            ans = min(ans, cur);
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