/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// B - Seek Grid

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
    vector<string> A(n);
    for (auto &x : A) cin >> x;
    vector<string> B(m);
    for (auto &x : B) cin >> x;
    
    auto check = [&](int x, int y) -> bool {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                if (B[i][j] != A[x + i][y + j]) return false;
            }
        }
        return true;
    };
    
    for (int i = 0; i + m - 1 < n; i++) {
        for (int j = 0; j + m - 1 < n; j++) {
            if (check(i, j)) {
                cout << i + 1 << " " << j + 1 << nl;
                return;
            }
        }
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