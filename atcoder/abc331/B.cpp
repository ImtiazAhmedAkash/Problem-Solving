/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Buy One Carton of Milk

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
    int n, s, m, l;
    cin >> n >> s >> m >> l;
    int ans = inf;
    for (int i = 0; i <= 20; i++) {
        for (int j = 0; j <= 20; j++) {
            for (int k = 0; k <= 20; k++) {
                int total = i * 6 + j * 8 + k * 12;
                if (total >= n) {
                    int cur = i * s + j * m + k * l;
                    ans = min(ans, cur);
                }
            }
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