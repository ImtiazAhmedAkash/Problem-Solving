/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// C - Trading Business

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "Dbug.h"
#else
#define dbg(...)
#endif

using ll = long long;
constexpr char nl = '\n';

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector A(n, vector<array<int, 3>>(m));
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            int a, b, c;
            cin >> a >> b >> c;
            A[i][j] = {a, b, c};
        }
    }
    
    int ans = 0;
    for (int i = 0; i < n; i++) {       // buy in i-th planet
        for (int j = 0; j < n; j++) {   // sell in j-th planet
            if (i == j) continue;
            vector<pair<int, int>> B;
            for (int l = 0; l < m; l++) {
                B.push_back({A[j][l][1] - A[i][l][0], l});
            }
            sort(B.begin(), B.end(), greater());
            
            int rem = k;
            int cur = 0;
            for (auto &[profit, indx] : B) {
                int taken = min(rem, A[i][indx][2]);
                cur += max(0, taken * profit);
                rem -= taken;
            }
            ans = max(ans, cur);
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