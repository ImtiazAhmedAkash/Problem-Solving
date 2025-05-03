/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// D - Logical Filling

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
    
    for (int i = 0; i < n; i++) {
        if (s[i] == 'o') {
            k--;
            if (i - 1 >= 0) s[i - 1] = '.';
            if (i + 1 < n) s[i + 1] = '.';
        }
    }
    
    if (k == 0) {
        for (int i = 0; i < n; i++) {
            if (s[i] == '?') s[i] = '.';
        }
        cout << s << nl;
        return;
    }
    
    vector<pair<int, int>> A;
    int maxOption = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '?') {
            int j = i;
            int cnt = 0;
            while (j < n && s[i] == s[j]) {
                cnt++, j++;
            }
            A.push_back({cnt, i});
            maxOption += (cnt + 1) / 2;
            i = j - 1;
        }
    }
    
    assert(maxOption >= k);
    
    if (maxOption == k) {
        for (auto &[cnt, indx] : A) {
            if (cnt % 2 == 0) continue;
            for (int i = indx; i < indx + cnt; i++) {
                s[i] = ((i - indx) % 2 == 0 ? 'o' : '.');
            }
        }
    }
    
    cout << s << nl;
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