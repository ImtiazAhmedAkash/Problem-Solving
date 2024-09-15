/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// The Strict Teacher (Hard Version)

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
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> A(m);
    for (auto &x : A) cin >> x;
    sort(A.begin(), A.end());

    while (q--) {
        int x;
        cin >> x;
        int L = 0, R = 0;
        int ans = 0;
        if (x < A.front()) {
            ans = A.front() - 1;
        } else if (x > A.back()) {
            ans = n - A.back();
        } else {
            auto it = upper_bound(A.begin(), A.end(), x);
            R = *it;
            L = *(prev(it));
            ans = (R - L) / 2;
        }
        cout << ans << nl;
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