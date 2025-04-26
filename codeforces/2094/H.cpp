/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// H - La Vaca Saturno Saturnita

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
const int N = 1e5;

vector divisor(N + 5, vector<int>());
void sieve() {
    for (int i = 2; i <= N; i++) {
        for (int j = i; j <= N; j += i) {
            divisor[j].push_back(i);
        }
    }
}

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> A(n + 1);
    map<int, vector<int>> pos;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        pos[A[i]].push_back(i);
    }
    
    while (q--) {
        int k, l, r;
        cin >> k >> l >> r;
        ll ans = 0;
        
        while (true) {
            int cur = r + 1;
            int curDivisor = -1;
            for (auto &x : divisor[k]) {
                if (pos.find(x) == pos.end()) continue;
                auto it = lower_bound(pos[x].begin(), pos[x].end(), l);
                if (it == pos[x].end()) continue;
                if (*it < cur) {
                    cur = *it;
                    curDivisor = x;
                }
            }
            
            if (curDivisor == -1) {
                ans += 1LL * (cur - l) * k;
                break;
            }
            else {
                ans += 1LL * (cur - l) * k;
                while (k % curDivisor == 0) {
                    k /= curDivisor;
                }
                l = cur;
            }
        }
        
        cout << ans << nl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    sieve();
    
    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        solve();
    }
    
    return 0;
}