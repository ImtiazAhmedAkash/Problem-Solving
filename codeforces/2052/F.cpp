/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// F - Fix Flooded Floor

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

vector<int> dx = {-1, +0, +1, +0};
vector<int> dy = {+0, +1, +0, -1};

void solve() {
    int n = 2, m;
    cin >> m;
    vector<string> A(2);
    for (auto &x : A) cin >> x;
    
    bool multiple = false;
    for (int j = 0; j < m; j++) {
        if (A[0][j] == '#' && A[1][j] == '#') continue;
        if (A[0][j] == '.' && A[1][j] == '#') {
            if (j + 1 < m && A[0][j + 1] == '.') {
                A[0][j] = A[0][j + 1] = '#';
            }
            else {
                cout << "None" << nl;
                return;
            }
        }
        else if (A[0][j] == '#' && A[1][j] == '.') {
            if (j + 1 < m && A[1][j + 1] == '.') {
                A[1][j] = A[1][j + 1] = '#';
            }
            else {
                cout << "None" << nl;
                return;
            }
        }
        else if (A[0][j] == '.' && A[1][j] == '.') {
            A[0][j] = A[1][j] = '.';
            if (j + 1 < m && A[0][j + 1] == '.' && A[1][j + 1] == '.') {
                multiple = true;
                A[0][j + 1] = A[1][j + 1] = '#';
                j++;
            }
        }
    }
    
    cout << (multiple ? "Multiple" : "Unique") << nl;
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