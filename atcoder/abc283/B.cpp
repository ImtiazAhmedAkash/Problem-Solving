/*  In the Name of ALLAH, the most gracious, the most merciful  */

// First Query Problem

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
    for (auto &x : A) cin >> x;
    int q;
    cin >> q;
    while (q--) {
        int op, k, x;
        cin >> op;
        if (op == 1) {
            cin >> k >> x;
            A[k - 1] = x;
        } else {
            cin >> k;
            cout << A[k - 1] << nl;
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