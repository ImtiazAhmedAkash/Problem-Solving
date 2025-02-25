/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// D - Harder Problem

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
    set<int> present, absent;
    for (int i = 1; i <= n; i++) {
        absent.insert(i);
    }
    vector<int> A(n);
    for (auto &x : A) {
        cin >> x;
        present.insert(x);
        absent.erase(x);
    }
    
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        if (present.count(A[i])) {
            ans[i] = A[i];
            present.erase(ans[i]);
        }
        else {
            ans[i] = *absent.begin();
            absent.erase(ans[i]);
        }
    }
    
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << nl;
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