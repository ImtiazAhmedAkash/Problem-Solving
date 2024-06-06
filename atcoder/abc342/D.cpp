/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Square Pair

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5;

void solve() {
    int n;
    cin >> n;
    vector<int> Sq;
    for (int i = 2; i * i <= N; i++) {
        Sq.push_back(i * i);
    }

    map<int, int> M;
    for (int t = 0; t < n; t++) {
        int x;
        cin >> x;
        for (int i = 0; i < Sq.size() && Sq[i] <= x; i++) {
            while (x % Sq[i] == 0) {
                x /= Sq[i];
            }
        }
        M[x]++;
    }

    ll ans = 0;
    for (auto [x, y] : M) {
        ans += 1LL * y * (y - 1) / 2;
    }
    if (M.find(0) != M.end()) {
        ans += 1LL * M[0] * (n - M[0]);
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