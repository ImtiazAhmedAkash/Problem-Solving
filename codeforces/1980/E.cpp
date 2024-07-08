/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Permutation of Rows and Columns

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
    int n, m;
    cin >> n >> m;
    vector A(n, vector<int>(m)), B(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> A[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> B[i][j];
        }
    }

    map<int, vector<int>> row, col;
    for (int i = 0; i < n; i++) {
        vector<int> C;
        for (int j = 0; j < m; j++) {
            C.push_back(A[i][j]);
        }
        sort(C.begin(), C.end());
        row[C.front()] = C;
    }
    for (int j = 0; j < m; j++) {
        vector<int> C;
        for (int i = 0; i < n; i++) {
            C.push_back(A[i][j]);
        }
        sort(C.begin(), C.end());
        col[C.front()] = C;
    }

    for (int i = 0; i < n; i++) {
        vector<int> C;
        for (int j = 0; j < m; j++) {
            C.push_back(B[i][j]);
        }
        sort(C.begin(), C.end());
        if (row.find(C.front()) == row.end() || row[C.front()] != C) {
            cout << "NO" << nl;
            return;
        }
    }

    for (int j = 0; j < m; j++) {
        vector<int> C;
        for (int i = 0; i < n; i++) {
            C.push_back(B[i][j]);
        }
        sort(C.begin(), C.end());
        if (col.find(C.front()) == col.end() || col[C.front()] != C) {
            cout << "NO" << nl;
            return;
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