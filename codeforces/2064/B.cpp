/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// B - Variety is Discouraged

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
    map<int, int> cnt;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        cnt[A[i]]++;
    }
    
    int ans = 0;
    int l = 0, r = 0;
    for (int i = 1; i <= n; i++) {
        if (cnt[A[i]] == 1) {
            int j = i;
            int cur = 0;
            while (j <= n && cnt[A[j]] == 1) {
                cur++;
                j++;
            }
            if (ans < cur) {
                ans = cur;
                l = i, r = j - 1;
            }
            i = j - 1;
        }
    }
    
    if (l == 0 && r == 0) {
        cout << 0 << nl;
    }
    else {
        cout << l << " " <<  r << nl;
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