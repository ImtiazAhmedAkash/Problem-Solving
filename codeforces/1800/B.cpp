/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// Count the Number of Pairs

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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> capital(26), small(26);
    for (auto &c : s) {
        if (isupper(c)) {
            capital[c - 'A']++;
        }
        else {
            small[c - 'a']++;
        }
    }
    
    for (int i = 0; i < 26; i++) {
        dbg(small[i], capital[i]);
    }
    
    int ans = 0;
    for (int i = 0; i < 26; i++) {
        int common = min(capital[i], small[i]);
        ans += common;
        int rem = max(capital[i], small[i]) - common;
        int op = min(k, rem / 2);
        ans += op;
        k -= op;
    }
    
    cout << ans << nl;
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