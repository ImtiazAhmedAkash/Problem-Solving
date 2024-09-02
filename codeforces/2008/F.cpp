/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Sakurako's Box

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
    int n;
    cin >> n;
    vector<int> A(n + 1);
    ll sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        sum += A[i];
        sum %= mod;
    }

    ll x = 0;
    for (int i = 1; i <= n; i++) {
        sum = (sum - A[i] + mod) % mod;
        x = (x + 1LL * A[i] * sum % mod) % mod;
    }
    ll y = inverseMod(1LL * n * (n - 1) / 2 % mod);
    cout << (1LL * x * y) % mod << nl;
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