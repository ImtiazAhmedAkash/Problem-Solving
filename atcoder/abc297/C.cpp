/*  In the Name of ALLAH, the most gracious, the most merciful  */

// PC on the Table

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define mod 998244353
#define N 300005
#define deb(x) cerr << #x << " = " << x << nl

void solve() {
    int n, m;
    cin >> n >> m;
    
    vector<string> a(n);
    for (auto &i : a) cin >> i;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j + 1 < m; j++) {
            if (a[i][j] == 'T' && a[i][j] == a[i][j + 1]) {
                a[i][j] = 'P';
                a[i][j + 1] = 'C';
            }
        }
    }
    
    for (auto i : a) cout << i << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
    
    return 0;
}