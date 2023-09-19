/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Vlad and a Pair of Numbers

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = (1 << 30);
const ll INF =(1LL << 62);
const int mod = 998244353;
const int N = 2e5 + 5;

void solve() {
    int x;
    cin >> x;
    int a = x, b = 0;
    int msb = __lg(x);
    for (int i = msb; i >= 0; i--) {
        if ((x & (1 << i)) == 0 && a + b + (1 << (i + 1)) <= 2 * x) {
            a |= (1 << i);
            b |= (1 << i);
        }
    }
    if (a + b == 2 * x) {
        cout << a << " " << b << nl;
    } else {
        cout << -1 << nl;
    }
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