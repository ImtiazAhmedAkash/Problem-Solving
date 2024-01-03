/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Union of Interval

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
        int x, y;
        cin >> x >> y;
        A[i] = {x, y};
    }
    sort(A.begin(), A.end());
    int l = A[0].first, r = A[0].second;
    for (int i = 1; i < n; i++) {
        if (l <= A[i].first && A[i].first <= r) {
            l = min(l, A[i].first);
            r = max(r, A[i].second);
        } else {
            cout << l << " " << r << nl;
            l = A[i].first;
            r = A[i].second;
        }
    }
    cout << l << " " << r << nl;
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