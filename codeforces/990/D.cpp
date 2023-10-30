/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Graph And Its Complement

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
    int n, a, b;
    cin >> n >> a >> b;
    
    bool ok = true;
    if ((n == 2 || n == 3) && (a * b) == 1) ok = false;
    else if (a > n || b > n || (a != 1 && b != 1)) ok = false;
    if (not ok) {
        cout << "NO" << nl;
        return;
    }
    
    cout << "YES" << nl;
    int m = max(a, b);
    vector A(n, vector(n, 0));
    for (int i = 0; i < n - m; i++) {
        A[i][i + 1] = A[i + 1][i] = 1;
    }
    if (m != a) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                A[i][j] ^= 1;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << A[i][j];
        }
        cout << nl;
    }
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