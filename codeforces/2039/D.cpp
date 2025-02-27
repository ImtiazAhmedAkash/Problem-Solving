/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// D - Shohag Loves GCD

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

vector<int> spf(N + 5);
void precalculate() {
    iota(spf.begin(), spf.end(), 0);
    for (int i = 2; i * i <= N; i++) {
        if (spf[i] == i) {
            for (int j = i; j <= N; j += i) {
                spf[j] = min(spf[j], i);
            }
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    priority_queue<int> pq;
    while (m--) {
        int x;
        cin >> x;
        pq.push(x);
    }
    
    auto count_prime = [&](int x) -> int {
        int cnt = 0;
        while (x > 1) {
            x /= spf[x];
            cnt++;
        }
        return cnt;
    };
    
    vector<int> ans(n + 1);
    for (int i = 1; i <= n; i++) {
        if ((i & (i - 1)) == 0) {
            if (pq.empty()) {
                cout << -1 << nl;
                return;
            }
            ans[i] = pq.top();
            pq.pop();
        }
        else {
            int cnt = count_prime(i);
            ans[i] = ans[(1 << cnt)];
        }
    }
    
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " \n"[i == n];
    }
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