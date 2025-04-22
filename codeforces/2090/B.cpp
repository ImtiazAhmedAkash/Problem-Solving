/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// B - Pushing Balls

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

vector<int> dx = {-1, +0};
vector<int> dy = {+0, -1};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> A(n);
    for (auto &x : A) cin >> x;
    
    for (int i = 0; i < n; i++) {
        int j = 0;
        while (j < m && A[i][j] != '0') {
            A[i][j] = 'x';
            j++;
        }
    }
    
    for (int j = 0; j < m; j++) {
        int i = 0;
        while (i < n && A[i][j] != '0') {
            A[i][j] = 'x';
            i++;
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (A[i][j] == '1') {
                cout << "NO" << nl;
                return;
            }
        }
    }
    
    cout << "YES" << nl;
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