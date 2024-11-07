/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// RANDOM_NIM - Random Nim

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 1e9 + 7;
const int N = 2e5 + 5;

int power(int a, int b) {
    int ans = 1;
    while (b) {
        if (b & 1) ans = 1LL * ans * a % mod;
        a = 1LL * a * a % mod;
        b /= 2;
    }
    return ans;
}
int inverseMod(int a) {
    return power(a, mod - 2);
}

void solve() {
    int n, d;
    cin >> n >> d;
    vector<int> A(n);
    for (auto &x : A) cin >> x;

    int a = d + 1;
    int b = 2 * d;
    int g = gcd(a, b);
    a /= g;
    b /= g;

    cout << 1LL * a * inverseMod(b) % mod << nl;
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