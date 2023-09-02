/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Overlapping Sheets

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int INF = (1 << 30);
const int mod = 998244353;
const int N = 2e5 + 5;

void solve() {
    vector v(105, vector(105, 0));
    int n;
    cin >> n;
    while (n--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        for (int i = a; i < b; i++) {
            for (int j = c; j < d; j++) {
                v[i][j] = 1;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= 100; i++) {
        for (int j = 0; j <= 100; j++) {
            ans += v[i][j];
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