/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// BALDIFF - Balance Difficulties

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
    vector<int> A(n);
    for (auto &x : A) cin >> x;

    vector<int> ans(n);
    vector<int> cur(n);
    auto check = [&](int mid) -> bool {
        cur[0] = A[0] + mid;
        for (int i = 1; i < n; i++) {
            if (cur[i - 1] + k < A[i] - mid) return false;
            cur[i] = min(cur[i - 1] + k, A[i] + mid);
        }
        ans = cur;
        return true;
    };

    int L = 0, R = inf;
    while (L < R) {
        int M = L + (R - L) / 2;
        if (check(M)) {
            R = M;
        } else {
            L = M + 1;
        }
    }

    cout << L << nl;
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i + 1 == n];
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