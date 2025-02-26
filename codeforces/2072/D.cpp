/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// D - For Wizards, the Exam Is Easy, but I Couldn't Handle It

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
    vector<int> A(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    
    int ans = 0;
    int l = 1, r = 1;
    for (int i = 1; i <= n; i++) {
        int cur = 0;
        for (int j = i + 1; j <= n; j++) {
            if (A[j] < A[i]) cur++;
            else if (A[j] > A[i]) cur--;
            if (ans < cur) {
                ans = cur;
                l = i, r = j;
            }
        }
    }
    
    cout << l << " " << r << nl;
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