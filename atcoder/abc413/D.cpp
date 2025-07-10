/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// D - Make Geometric Sequence

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "Dbug.h"
#else
#define dbg(...)
#endif

using ll = long long;
constexpr char nl = '\n';
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;

void solve() {
    int n;
    cin >> n;
    vector<ll> A(n);
    for (auto &x : A) cin >> x;
    
    if (count(A.begin(), A.end(), A.front()) == n) {
        cout << "Yes" << nl;
        return;
    }
    
    int pos = count(A.begin(), A.end(), A.front());
    int neg = count(A.begin(), A.end(), -A.front());
    if (pos + neg == n && min(pos, neg) == n / 2) {
        cout << "Yes" << nl;
        return;
    }
    
    sort(A.begin(), A.end(), [&](ll x, ll y) {
        return abs(x) < abs(y);
    });
    
    for (int i = 1; i + 1 < n; i++) {
        if (A[i] * A[i] != A[i - 1] * A[i + 1]) {
            cout << "No" << nl;
            return;
        }
    }
    
    cout << "Yes" << nl;
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