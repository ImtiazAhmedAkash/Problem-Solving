/*  In the Name of ALLAH, the most gracious, the most merciful  */

// T-shirts

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e15;
const int mod = 998244353;
const int N = 2e5;

void solve() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;

    auto check = [&](int mid) -> bool {
        int plain = m, logo = mid;
        for (auto c : s) {
            if (c == '0') {
                plain = m;
                logo = mid;
            } else if (c == '1') {
                plain ? plain-- : logo--;
            } else {
                logo--;
            }
            if (logo < 0) return false;
        }
        return true;
    };

    int L = 0, R = 1000;
    while (L < R) {
        int M = L + (R - L) / 2;
        if (check(M)) {
            R = M;
        } else {
            L = M + 1;
        }
    }
    cout << L << nl;
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