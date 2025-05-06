/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// B - Grid Rotation

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
    int n;
    cin >> n;
    vector<string> A(n), B(n);
    for (auto &x : A) cin >> x;
    for (auto &x : B) cin >> x;
    
    auto match = [&](vector<string> C) -> int {
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (C[i][j] != B[i][j]) ans++;
            }
        }
        return ans;
    };
    
    auto rotate = [&]() -> void {
        vector<string> C;
        for (int j = 0; j < n; j++) {
            string s;
            for (int i = n - 1; i >= 0; i--) {
                s += A[i][j];
            }
            C.push_back(s);
        }
        A = C;
    };
    
    int ans = match(A);
    for (int i = 1; i < 4; i++) {
        rotate();
        ans = min(ans, i + match(A));
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