/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Modular Equations

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define mod 998244353
#define N 300005
#define deb(x) cerr << #x << " = " << x << nl

void solve() {
    int a, b;
    cin >> a >> b;
    if (a == b) {
        cout << "infinity" << nl;
    } else if (a < b) {
        cout << 0 << nl;
    } else {
        int ans = 0;
        int x = a - b;
        for (ll i = 1; i * i <= x; i++) {
            if (x % i == 0) {
                if (i > b) ans++;
                if ((x / i) != i && (x / i) > b) ans++;
            }
        }
        cout << ans << nl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}