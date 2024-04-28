/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Card Exchange

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
    int n, k;
    cin >> n >> k;
    map<int, int> M;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        M[x]++;
    }
    for (auto [x, y] : M) {
        if (y >= k) {
            cout << k - 1 << nl;
            return;
        }
    }
    cout << n << nl;
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