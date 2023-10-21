/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Template Matching

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
    vector<string> A(n), B(m);
    for (int i = 0; i < n; i++) cin >> A[i];
    for (int i = 0; i < m; i++) cin >> B[i];
    string ans = "No";
    for (int i = 0; i + m <= n; i++) {
        for (int j = 0; j + m <= n; j++) {
            if (A[i][j] == B[0][0]) {
                bool ok = true;
                for (int k = 0; k < m; k++) {
                    for (int l = 0; l < m; l++) {
                        if (A[i + k][j + l] != B[k][l]) {
                            ok = false;
                        }
                    }
                }
                if (ok) ans = "Yes";
            }
        }
    }
    cout << ans << nl;
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