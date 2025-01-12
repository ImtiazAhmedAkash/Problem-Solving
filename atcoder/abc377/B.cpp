/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Avoid Rook Attack

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
    int n = 8;
    vector<string> A(n);
    for (auto &x : A) cin >> x;
    
    for (int i = 0; i < n; i++) {
        bool ok = false;
        for (int j = 0; j < n; j++) {
            if (A[i][j] == '#') {
                ok = true;
            }
        }
        
        if (ok) {
            for (int j = 0; j < n; j++) {
                if (A[i][j] != '#') {
                    A[i][j] = 'x';
                }
            }
        }
    }
    
    for (int j = 0; j < n; j++) {
        bool ok = false;
        for (int i = 0; i < n; i++) {
            if (A[i][j] == '#') {
                ok = true;
            }
        }
        
        if (ok) {
            for (int i = 0; i < n; i++) {
                if (A[i][j] != '#') {
                    A[i][j] = 'x';
                }
            }
        }
    }
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (A[i][j] == '.') {
                ans++;
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