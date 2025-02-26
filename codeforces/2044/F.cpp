/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// F - Easy Demon Problem

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
const int N = 2e5;

vector divisor(N + 5, vector<int>());
void precalculate() {
    for (int i = 1; i <= N; i++) {
        for (int j = i; j <= N; j += i) {
            divisor[j].push_back(i);
        }
    }
}

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> A(n);
    ll sumA = 0;
    for (auto &x : A) {
        cin >> x;
        sumA += x;
    }
    vector<int> B(m);
    ll sumB = 0;
    for (auto &x : B) {
        cin >> x;
        sumB += x;
    }
    
    auto adjust = [&](int x) -> int {
        return x + N;
    };

    vector<int> cntA(2 * N + 5), cntB(2 * N + 5);
    for (auto &x : A) {
        ll y = sumA - x;
        if (-N <= y && y <= N) {
            y = adjust(y);
            cntA[y] = 1;
        }
    }
    for (auto &x : B) {
        ll y = sumB - x;
        if (-N <= y && y <= N) {
            y = adjust(y);
            cntB[y] = 1;
        }
    }

    while (q--) {
        int x;
        cin >> x;
        bool ok = false;
        for (auto &cd : divisor[abs(x)]) {
            int a = cd;
            int b = x / cd;
            int c = -a;
            int d = -b;
            a = adjust(a);
            b = adjust(b);
            c = adjust(c);
            d = adjust(d);
            if ((cntA[a] && cntB[b]) || (cntA[b] && cntB[a]) || (cntA[c] && cntB[d]) || (cntA[d] && cntB[c])) {
                ok = true;
                break;
            }
        }
        cout << (ok ? "YES" : "NO") << nl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    precalculate();
    
    int T = 1;
    for (int t = 1; t <= T; t++) {
        solve();
    }

    return 0;
}