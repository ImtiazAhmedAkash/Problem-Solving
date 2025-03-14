/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// C - Breach of Faith

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
    n *= 2;
    vector<ll> A(n);
    set<ll> st;
    for (auto &x : A) {
        cin >> x;
        st.insert(x);
    }
    
    sort(A.begin(), A.end(), greater());
    
    // odd term is missing
    ll a1 = 0;
    for (int i = 0; i + 1 < n; i += 2) {
        a1 += A[i] - A[i + 1];
    }
    if (!st.count(a1)) {
        cout << a1 << " ";
        for (int i = 0; i < n; i++) {
            cout << A[i] << " \n"[i + 1 == n];
        }
        return;
    }
    
    // even term is missing
    ll a2 = A.front() + A.back();
    for (int i = 1; i + 1 < n; i += 2) {
        a2 += A[i] - A[i + 1];
    }
    if (!st.count(a2)) {
        cout << A.front() << " " << a2 << " ";
        for (int i = 1; i < n; i++) {
            cout << A[i] << " \n"[i + 1 == n];
        }
        return;
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