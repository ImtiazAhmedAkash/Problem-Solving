/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// D - Penchick and Desert Rabbit

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
    
    vector<int> pref(n + 1, 0), suff(n + 2, 0);
    pref[1] = A[1];
    for (int i = 2; i <= n; i++) {
        pref[i] = max(pref[i - 1], A[i]);
    }
    suff[n] = A[n];
    for (int i = n - 1; i >= 1; i--) {
        suff[i] = min(suff[i + 1], A[i]);
    }
    
    vector<int> ans(n + 1);
    ans[n] = pref[n];
    for (int i = n - 1; i >= 1; i--) {
        if (pref[i] > suff[i + 1]) {
            ans[i] = ans[i + 1];
        } 
        else {
            ans[i] = pref[i];
        }
    }
    
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " \n"[i == n];
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