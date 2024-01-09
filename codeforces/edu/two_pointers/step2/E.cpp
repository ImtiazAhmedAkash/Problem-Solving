/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Segments with Small Set

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 1e5 + 5;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (auto &x : A) cin >> x;
    ll ans = 0, cur = 0;
    vector<int> cnt(N);
    for (int l = 0, r = 0; r < n; r++) {
        cnt[A[r]]++;
        if (cnt[A[r]] == 1) {
            cur++;
        }
        while (l <= r && k < cur) {
            cnt[A[l]]--;
            if (cnt[A[l]] == 0) {
                cur--;
            }
            l++;
        }
        ans += (r - l + 1);
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