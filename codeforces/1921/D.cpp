/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Very Different Array

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
    int n, m;
    cin >> n >> m;
    vector<int> A(n);
    for (auto &x : A) cin >> x;
    vector<int> B(m);
    for (auto &x : B) cin >> x;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    ll ans = 0;
    int la = 0, ra = n - 1, lb = 0, rb = m - 1;
    while (la <= ra) {
        if (abs(A[la] - B[rb]) >= abs(A[ra] - B[lb])) {
            ans += abs(A[la] - B[rb]);
            la++, rb--;
        } else {
            ans += abs(A[ra] - B[lb]);
            lb++, ra--;
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