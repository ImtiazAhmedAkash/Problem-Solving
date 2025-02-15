/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// F - K-th Largest Triplet

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
    int n, x;
    cin >> n >> x;
    vector<ll> A(n);
    for (auto &x : A) cin >> x;
    vector<ll> B(n);
    for (auto &x : B) cin >> x;
    vector<ll> C(n);
    for (auto &x : C) cin >> x;

    sort(A.begin(), A.end(), greater());
    sort(B.begin(), B.end(), greater());
    sort(C.begin(), C.end(), greater());

    priority_queue<array<ll, 4>> pq;
    set<array<int, 3>> st;
    auto calculate = [&](int i, int j, int k) -> void {
        if (i < n && j < n && k < n && st.find({i, j, k}) == st.end()) {
            st.insert({i, j, k});
            ll val = A[i] * B[j] + A[i] * C[k] + B[j] * C[k];
            pq.push({val, i, j, k});
        }
    };

    calculate(0, 0, 0);

    while (x > 1) {
        x--;
        auto [val, i, j, k] = pq.top();
        pq.pop();
        calculate(i + 1, j, k);
        calculate(i, j + 1, k);
        calculate(i, j, k + 1);
    }

    cout << pq.top()[0] << nl;
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