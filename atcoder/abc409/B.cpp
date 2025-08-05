/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// B - Citation

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
    vector<int> A(n);
    for (auto &x : A) cin >> x;
    
    auto check = [&](int mid) -> bool {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            cnt += (mid <= A[i]);
        }
        return cnt >= mid;
    };
    
    int L = 0, R = inf;
    while (L < R) {
        int M = L + (R - L + 1) / 2;
        if (check(M)) L = M;
        else R = M - 1;
    }
    
    cout << R << nl;
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