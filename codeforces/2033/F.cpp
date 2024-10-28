/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Kosuke's Sloth

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 1e9 + 7;
const int N = 2e5 + 5;

void solve() {
    ll n, k;
    cin >> n >> k;
    n %= mod;

    if (k == 1) {
        cout << n << nl;
        return;
    }

    int a = 1, b = 1;
    for (int i = 3; ; i++) {
        int c = (a + b) % k;
        if (c == 0) {
            cout << 1LL * n * i % mod << nl;
            return;
        }
        a = b % k;
        b = c % k;
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