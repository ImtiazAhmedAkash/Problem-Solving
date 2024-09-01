/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Count Arithmetic Subarrays

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
    vector<int> A(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    ll ans = n;
    for (int l = 1, r = 2; l < n && r <= n;) {
        int diff = A[r] - A[l];
        while (r <= n && A[r] - A[r - 1] == diff) {
            r++;
        }
        int cur = r - l;
        ans += 1LL * cur * (cur - 1) / 2;
        l = r - 1;
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