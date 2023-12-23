/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Not Divisible

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 1e6;

void solve() {
    int n;
    cin >> n;
    vector<int> A(n), cnt(N + 5);
    vector<bool> ok(N + 5, true);
    for (auto &x : A) {
        cin >> x;
        cnt[x]++;
    }
    sort(A.begin(), A.end());
    for (int i = 0; i < n; i++) {
        if (not ok[A[i]]) continue;
        if (cnt[A[i]] >= 2) ok[A[i]] = false;
        for (int j = 2 * A[i]; j <= A.back(); j += A[i]) {
            if (cnt[j]) ok[j] = false;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += ok[A[i]];
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