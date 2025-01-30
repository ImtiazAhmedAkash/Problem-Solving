/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// Penalty Kick

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;

void solve() {
    int n, keeperA, keeperB;
    cin >> n >> keeperA >> keeperB;
    vector<int> A(n);
    for (auto &x : A) cin >> x;
    vector<int> B(n);
    for (auto &x : B) cin >> x;
    
    int cntA = 0, cntB = 0;
    int mxA = 0, mxB = 0;
    for (int i = 0; i < n; i++) {
        if (A[i] >= keeperB / 2) cntA++;
        if (B[i] >= keeperA / 2) cntB++;
        mxA = max(mxA, A[i]);
        mxB = max(mxB, B[i]);
    }
    
    if (cntA > cntB) {
        cout << "Alice" << nl;
    } else if (cntA < cntB) {
        cout << "Bob" << nl;
    } else {
        cout << (mxA > mxB ? "Alice" : "Bob") << nl;
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