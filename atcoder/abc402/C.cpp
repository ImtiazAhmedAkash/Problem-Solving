/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// C - Dislike Foods

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
    int n, m;
    cin >> n >> m;
    vector<set<int>> dish(m + 1);
    vector<vector<int>> need(n + 1);
    for (int i = 1; i <= m; i++) {
        int x;
        cin >> x;
        while (x--) {
            int y;
            cin >> y;
            dish[i].insert(y);
            need[y].push_back(i);
        }
    }
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        for (auto &y : need[x]) {
            dish[y].erase(x);
            if (dish[y].empty()) ans++;
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