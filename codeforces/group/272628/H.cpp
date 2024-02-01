/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Plan

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
    int n, q;
    cin >> n >> q;
    vector<pair<int, int>> A(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        A[i] = {x, i + 1};
    }
    sort(A.begin(), A.end());
    while (q--) {
        int x;
        cin >> x;
        auto it = lower_bound(A.begin(), A.end(), make_pair(x, 0));
        if (it == A.end() || (*it).first != x) {
            cout << "No" << nl;
        } else {
            cout << "Yes " << (*it).second << nl;
        }
    }
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