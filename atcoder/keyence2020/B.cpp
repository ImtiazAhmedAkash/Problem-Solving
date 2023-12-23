/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Robot Arms

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
    vector<pair<int, int>> A(n);
    for (int i = 0; i < n; i++) {
        int x, l;
        cin >> x >> l;
        A[i] = {x + l, x - l};
    }
    sort(A.begin(), A.end());
    int ans = 0, lst = -inf;
    for (int i = 0; i < n; i++) {
        if (lst <= A[i].second) {
            ans++;
            lst = A[i].first;
        }
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