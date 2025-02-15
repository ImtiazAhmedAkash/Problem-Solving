/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// D - Gravity

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "Dbug.h"
#else
#define dbg(...)
#endif

using ll = long long;
constexpr char nl = '\n';

const int inf = 2e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;

void solve() {
    int n, w;
    cin >> n >> w;
    vector col(w + 1, vector<pair<int, int>>());
    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        col[x].push_back({y, i});
    }
    
    int turn = inf;
    for (int i = 1; i <= w; i++) {
        turn = min((int)col[i].size(), turn);
        sort(col[i].begin(), col[i].end(), greater());
    }
    
    vector<int> deathTime(n + 1, inf);
    for (int i = 1; i <= turn; i++) {
        vector<int> tmp;
        int time = 0;
        for (int j = 1; j <= w; j++) {
            time = max(time, col[j].back().first);
            tmp.push_back(col[j].back().second);
            col[j].pop_back();
        }
        while (!tmp.empty()) {
            deathTime[tmp.back()] = time;
            tmp.pop_back();
        }
    }
    
    int q;
    cin >> q;
    while (q--) {
        int t, block;
        cin >> t >> block;
        cout << (deathTime[block] <= t ? "No" : "Yes") << nl;
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