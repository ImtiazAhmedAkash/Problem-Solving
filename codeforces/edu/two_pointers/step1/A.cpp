/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Merging Arrays

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
    vector<int> A(n), B(m);
    for (auto &x : A) cin >> x;
    for (auto &x : B) cin >> x;
    int i = 0, j = 0;
    while (i < A.size() || j < B.size()) {
        if (j == B.size() || (i < A.size() && A[i] < B[j])) {
            cout << A[i++] << " ";
        } else {
            cout << B[j++] << " ";
        }
    }
    cout << nl;
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