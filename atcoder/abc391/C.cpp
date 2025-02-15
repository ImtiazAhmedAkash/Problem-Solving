/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// C - Pigeonhole Query

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
    int n, q;
    cin >> n >> q;
    vector<int> pigeon(n + 1);
    iota(pigeon.begin(), pigeon.end(), 0);
    vector<int> nest;
    nest.assign(n + 1, 1);
    
    int ans = 0;
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int p, h;
            cin >> p >> h;
            
            int prevLocation = pigeon[p];
            nest[prevLocation]--;
            if (nest[prevLocation] == 1) {
                ans--;
            }
            
            pigeon[p] = h;
            nest[h]++;
            if (nest[h] == 2) {
                ans++;
            }
        }
        else {
            cout << ans << nl;
        }
    }
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