/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// B - Quasi Binary

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
    
    string s = to_string(n);
    int maxi = *max_element(s.begin(), s.end()) - '0';
    
    vector<string> ans(maxi);
    for (int i = 0; i < s.size(); i++) {
        for (int j = 0; j < s[i] - '0'; j++) {
            ans[j] += '1';
        }
        for (int j = s[i] - '0'; j < maxi; j++) {
            ans[j] += '0';
        }
        
    }
    
    cout << maxi << nl;
    for (auto &x : ans) {
        cout << stoi(x) << " ";
    }
    cout << nl;
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