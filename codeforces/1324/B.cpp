/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// Yet Another Palindrome Problem

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
    
    vector<int> firstIndx(n + 1), lastIndx(n + 1);
    for (int i = 0; i < n; i++) {
        lastIndx[A[i]] = i;
    }
    for (int i = n - 1; i >= 0; i--) {
        firstIndx[A[i]] = i;
    }
    
    for (int i = 1; i <= n; i++) {
        if (firstIndx[i] + 1 < lastIndx[i]) {
            cout << "YES" << nl;
            return;
        }
    }
    
    cout << "NO" << nl;
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