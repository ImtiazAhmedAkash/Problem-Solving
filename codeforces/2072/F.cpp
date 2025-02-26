/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// F - Goodbye, Banker Life

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
const int N = 1e6;

vector<int> powerOfTwo(N + 5);
void precalculate() {
    for (int i = 1; i <= N; i++) {
        int cur = 0;
        int tmp = i;
        while (tmp) {
            cur += tmp / 2;
            tmp /= 2;
        }
        powerOfTwo[i] = cur;
    }
}

void solve() {
    int n, k;
    cin >> n >> k;
    n--;
    for (int r = 0; r <= n; r++) {
        int cnt = powerOfTwo[n] - powerOfTwo[r] - powerOfTwo[n - r];
        cout << (cnt ? 0 : k) << " ";
    }
    cout << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    precalculate();
    
    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        solve();
    }
    
    return 0;
}