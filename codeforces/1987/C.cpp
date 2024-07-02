/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Basil's Garden

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
    ll ans = A.back();
    ll last = A.back();
    for (int i = n - 2; i >= 0; i--) {
        if (A[i] <= A[i + 1]) {
            last++;
        } else {
            last = max((ll)A[i], last + 1);
        }
        ans = max(ans, last);
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