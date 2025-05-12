/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// B - Crazy Permutation

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

    vector<int> ans = {1};
    int Xor = 1;
    for (int i = 2; i <= n; i++) {
        if (Xor ^ i) {
            Xor ^= i;
            ans.push_back(i);
        }
        else {
            ans.push_back(i + 1);
            ans.push_back(i);
            Xor ^= i;
            Xor ^= (i + 1);
            i++;
        }
    }
    
    if (ans.size() != n) {
        cout << -1 << nl;
        return;
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
    for (int t = 1; t <= T; t++) {
        solve();
    }
    
    return 0;
}