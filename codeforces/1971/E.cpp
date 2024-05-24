/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Find the Car

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
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> A(k + 1), B(k + 1);
    for (int i = 1; i <= k; i++) {
        cin >> A[i];
    }
    for (int i = 1; i <= k; i++) {
        cin >> B[i];
    }

    while (q--) {
        int x;
        cin >> x;
        int indx = prev(upper_bound(A.begin(), A.end(), x)) - A.begin();
        if (A[indx] == x) {
            cout << B[indx] << " ";
            continue;
        }
        ll ans = B[indx];
        int t = B[indx + 1] - B[indx];
        int d = A[indx + 1] - A[indx];
        ans += (1LL * t * (x - A[indx]) / d);
        cout << ans << " ";
    }
    cout << nl;
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