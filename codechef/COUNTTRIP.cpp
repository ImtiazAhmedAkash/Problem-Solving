/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// COUNTTRIP - Count Triplets

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
    int n;
    cin >> n;
    vector<int> A(n);
    for (auto &x : A) cin >> x;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int mn = max(0, i - 100);
        int mx = min(n - 1, i + 100);
        for (int k = mn; k <= mx; k++) {
            // j < i <= k
            int j = i + k - abs(A[i] - A[k]);
            if (j % 2 == 0 && mn <= j / 2 && j / 2 < min(i, k)) {
                ans++;
            }

            // i <= j <= k
            if (abs(A[i] - A[k]) == abs(k - i)) {
                ans += (abs(k - i) + 1);
            }

            // i <= k < j
            j = i + k + abs(A[i] - A[k]);
            if (j % 2 == 0 && j / 2 <= mx && j / 2 > max(i, k)) {
                ans++;
            }
        }
    }

    cout << ans << nl;
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