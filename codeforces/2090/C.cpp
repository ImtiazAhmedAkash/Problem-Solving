/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// C - Dining Hall

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
const int mod = 1e9 + 7;
const int N = 1e7;

void solve() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (auto &x : A) cin >> x;
    
    auto dist = [&] (int x, int y) -> int {
        return x + y + (x % 3 == 2 && y % 3 == 2 ? 2 : 0);
    };
    
    set<array<int, 3>> st, found, full, notFull;
    st.insert({dist(1, 1), 1, 1});
    found.insert({dist(1, 1), 1, 1});
    while (full.size() != n && !st.empty()) {
        auto [_, x, y] = *st.begin();
        full.insert({dist(x, y), x, y});
        for (int i = 0; i <= 1; i++) {
            for (int j = 0; j <= 1; j++) {
                notFull.insert({dist(x + i, y + j), x + i, y + j});
            }
        }
        st.erase(st.begin());
        
        for (int i = 0; i <= 1; i++) {
            for (int j = 0; j <= 1; j++) {
                int nx = x + 3 * i;
                int ny = y + 3 * j;
                if (found.find({dist(nx, ny), nx, ny}) == found.end()) {
                    st.insert({dist(nx, ny), nx, ny});
                    found.insert({dist(nx, ny), nx, ny});
                }
            }
        }
    }
    
    vector<pair<int, int>> ans;
    for (int i = 0; i < n; i++) {
        if (A[i] == 0) {
            auto [_, x, y] = *full.begin();
            ans.push_back({x, y});
            notFull.erase(*full.begin());
            full.erase(full.begin());
        }
        else {
            auto [_, x, y] = *notFull.begin();
            ans.push_back({x, y});
            full.erase(*notFull.begin());
            notFull.erase(notFull.begin());
        }
    }
    
    for (auto &[x, y] : ans) {
        cout << x << " " << y << nl;
    }
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