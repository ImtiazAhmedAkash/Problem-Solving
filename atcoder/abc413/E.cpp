/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// E - Reverse 2^i

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
    vector<int> A(1 << n);
    for (auto &x : A) cin >> x;
    
    auto fun = [&](auto&& self, int l, int r) -> vector<int> {
        if (l == r) return {A[l]};
        
        int mid = (l + r) / 2;
        vector<int> left = self(self, l, mid);
        vector<int> right = self(self, mid + 1, r);
        if (left.front() > right.front()) swap(left, right);
        for (auto &x : right) {
            left.push_back(x);
        }
        
        return left;
    };
    
    vector<int> ans = fun(fun, 0, (1 << n) - 1);
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << nl;
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