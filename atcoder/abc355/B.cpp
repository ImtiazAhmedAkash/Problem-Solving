/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Piano 2

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
    vector<pair<int, int>> A(n + m);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        A[i] = {x, 1};
    }
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        A[n + i] = {x, 2};
    }
    sort(A.begin(), A.end());
    for (int i = 0; i + 1 < n + m; i++) {
        if (A[i].second == 1 && A[i].second == A[i + 1].second) {
            cout << "Yes" << nl;
            return;
        }
    }
    cout << "No" << nl;
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