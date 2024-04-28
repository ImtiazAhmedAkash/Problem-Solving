/*  In the Name of ALLAH, the most gracious, the most merciful  */

// AU7_5 - STUDENTS

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 5000011;
const int N = 2e5 + 5;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> B(n + 1), G(n + 1);
    B[1] = G[1] = 1;
    for (int i = 2; i <= n; i++) {
        B[i] = (i - k - 1 > 0 ? 0LL + B[i - k - 1] + G[i - k - 1] : 1) % mod;
        G[i] = (0LL + G[i - 1] + B[i - 1]) % mod;
    }
    cout << (0LL + B[n] + G[n]) % mod << nl;
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