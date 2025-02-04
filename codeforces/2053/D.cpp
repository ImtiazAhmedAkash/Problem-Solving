/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// Refined Product Optimality

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

int power(int a, int b) {
    int ans = 1;
    while (b) {
        if (b & 1) ans = 1LL * ans * a % mod;
        a = 1LL * a * a % mod;
        b /= 2;
    }
    return ans;
}
int inverseMod(int a) {
    return power(a, mod - 2);
}

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> A(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    vector<int> B(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> B[i];
    }
    
    auto tmpA = A;
    auto tmpB = B;
    sort(tmpA.begin(), tmpA.end());
    sort(tmpB.begin(), tmpB.end());
    
    multiset<pair<int, int>> msA, msB;
    ll ans = 1;
    for (int i = 1; i <= n; i++) {
        ans = (ans * min(tmpA[i], tmpB[i])) % mod;
        msA.insert({tmpA[i], tmpB[i]});
        msB.insert({tmpB[i], tmpA[i]});
    }
    
    cout << ans << " ";
    
    while (q--) {
        int op, indx;
        cin >> op >> indx;
        if (op == 1) {
            int prevVal = A[indx];
            auto it = prev(msA.upper_bound({prevVal, inf}));
            auto [x, y] = *it;
            ans = (ans * inverseMod(min(x, y))) % mod;
            msA.erase(msA.find({x, y}));
            msB.erase(msB.find({y, x}));
            
            x++;
            A[indx] = x;
            ans = (ans * min(x, y)) % mod;
            msA.insert({x, y});
            msB.insert({y, x});
        }
        else {
            int prevVal = B[indx];
            auto it = prev(msB.upper_bound({prevVal, inf}));
            auto [x, y] = *it;
            ans = (ans * inverseMod(min(x, y))) % mod;
            msB.erase(msB.find({x, y}));
            msA.erase(msA.find({y, x}));
            
            x++;
            B[indx] = x;
            ans = (ans * min(x, y)) % mod;
            msB.insert({x, y});
            msA.insert({y, x});
        }
        
        cout << ans << " ";
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