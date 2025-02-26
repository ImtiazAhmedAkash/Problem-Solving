/*  In the Name of ALLAH, the most gracious, the most merciful  */

// C - Showering

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
    int n, s, m;
    cin >> n >> s >> m;
    vector<int> L(n + 2), R(n + 2);
    for (int i = 1; i <= n; i++) {
        cin >> L[i] >> R[i];
    }
    
    L.back() = R.back() = m;
    
    for (int i = 1; i <= n + 1; i++) {
        if (L[i] - R[i - 1] >= s) {
            cout << "YES" << nl;
            return;
        }
    }
    
    cout << "NO" << nl;
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