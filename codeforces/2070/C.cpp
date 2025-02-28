/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// C - Limited Repainting

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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> A(n);
    for (auto &x : A) cin >> x;
    
    auto check = [&](int mid) -> bool {
        int op = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'B' && A[i] > mid) {
                int j = i;
                while (j < n) {
                    if (s[j] == 'R' && A[j] > mid) break;
                    j++;
                }
                op++;
                i = j - 1;
            }
        }
        return op <= k;
    };
    
    int L = 0, R = inf;
    while (L < R) {
        int M = L + (R - L) / 2;
        if (check(M)) R = M;
        else L = M + 1;
    }
    
    cout << L << nl;
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