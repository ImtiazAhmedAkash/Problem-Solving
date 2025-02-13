/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// E - White Magic

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
    int n;
    cin >> n;
    int zero = 0;
    vector<int> A(n);
    for (auto &x : A) {
        cin >> x;
        if (x == 0) zero++;
    }
    
    if (not zero) {
        cout << n << nl;
        return;
    }
    
    zero = -1;
    for (int i = 0; i < n; i++) {
        if (A[i] == 0) {
            zero = i;
            break;
        }
    }
    
    vector<int> B;
    for (int i = 0; i <= zero; i++) {
        B.push_back(A[i]);
    }
    for (int i = zero + 1; i < n; i++) {
        if (A[i] != 0) {
            B.push_back(A[i]);
        }
    }
    n = B.size();
    
    vector<int> suff_mex(n);
    int mex = 0;
    set<int> present;
    for (int i = n - 1; i >= 0; i--) {
        present.insert(B[i]);
        while (present.count(mex)) mex++;
        suff_mex[i] = mex;
    }
    
    int mini = inf;
    for (int i = 0; i + 1 < n; i++) {
        mini = min(mini, B[i]);
        if (mini < suff_mex[i + 1]) {
            cout << n - 1 << nl;
            return;
        }
    }
    
    cout << n << nl;
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