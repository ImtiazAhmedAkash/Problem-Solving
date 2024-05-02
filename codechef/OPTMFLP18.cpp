/*  In the Name of ALLAH, the most gracious, the most merciful  */

// OPTMFLP18 - Optimal Flip

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
    for (auto& x : A) cin >> x;

    ll ans = 0;
    int last_even = -1;
    for (int i = 0; i < n; i++) {
        if (A[i] % 2 == 0) {
            last_even = i;
        }
        ans += last_even + 1;
    }

    vector<int> prev_even(n);
    int indx = -1;
    for (int i = 0; i < n; i++) {
        if (A[i] & 1) {
            prev_even[i] = indx;
        } else {
            indx = i;
        }
    }
    vector<int> next_even(n);
    indx = n;
    for (int i = n - 1; i >= 0; i--) {
        if (A[i] & 1) {
            next_even[i] = indx;
        } else {
            indx = i;
        }
    }

    ll cur = 0;
    for (int i = 0; i < n; i++) {
        if (A[i] & 1) {
            cur = max(cur, 1LL * (i - prev_even[i]) * (next_even[i] - i));
        }
    }
    ans += cur;
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