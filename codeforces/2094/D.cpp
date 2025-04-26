/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// D - Tung Tung Sahur

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
    string s, t;
    cin >> s >> t;
    vector<pair<int, int>> A, B;
    for (int i = 0; i < s.size(); i++) {
        int j = i;
        int cnt = 0;
        while (j < s.size() && s[i] == s[j]) {
            cnt++, j++;
        }
        A.push_back({s[i], cnt});
        i = j - 1;
    }
    for (int i = 0; i < t.size(); i++) {
        int j = i;
        int cnt = 0;
        while (j < t.size() && t[i] == t[j]) {
            cnt++, j++;
        }
        B.push_back({t[i], cnt});
        i = j - 1;
    }
    
    if (A.size() != B.size()) {
        cout << "NO" << nl;
        return;
    }
    
    for (int i = 0; i < A.size(); i++) {
        auto [a, b] = A[i];
        auto [c, d] = B[i];
        if (a != c || b > d || 2 * b < d) {
            cout << "NO" << nl;
            return;
        }
    }
    
    cout << "YES" << nl;
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