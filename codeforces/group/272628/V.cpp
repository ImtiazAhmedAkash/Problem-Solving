/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Compiler_101

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 30;

void solve() {
    int n;
    cin >> n;
    vector<int> A(n);
    int mx_or = 0;
    for (auto &x : A) {
        cin >> x;
        mx_or |= x;
    }

    int ans = inf, cur = 0;
    vector<int> B(30);
    for (int l = 0, r = 0; r < n; r++) {
        cur |= A[r];
        for (int bit = 0; bit < 30; bit++) {
            if (A[r] & (1 << bit)) {
                B[bit]++;
            }
        }
        while (l <= r && cur == mx_or) {
            ans = min(ans, r - l + 1);
            for (int bit = 0; bit < 30; bit++) {
                if (A[l] & (1 << bit)) {
                    B[bit]--;
                    if (B[bit] == 0) {
                        cur ^= (1 << bit);
                    }
                }
            }
            l++;
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