/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Choosing Cubes

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
    int n, f, k;
    cin >> n >> f >> k;
    vector<int> A(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    int val = A[f];
    sort(A.begin() + 1, A.end(), greater());
    if (A[k] > val) {
        cout << "NO" << nl;
    } else if (A[k] < val) {
        cout << "YES" << nl;
    } else if (k == n || A[k + 1] < val) {
        cout << "YES" << nl;
    } else {
        cout << "MAYBE" << nl;
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