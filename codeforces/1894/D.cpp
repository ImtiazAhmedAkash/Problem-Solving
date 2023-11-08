/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Neutral Tonality

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9 + 5;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> A(n + 1), B(m);
    A[0] = inf;
    for (int i = 1; i <= n; i++)
        cin >> A[i];
    for (auto &x : B)
        cin >> x;

    sort(B.begin(), B.end(), greater());

    int i = 1, j = 0;
    while (i <= n || j < m) {
        if (i == n + 1) {
            cout << B[j++] << " ";
        } else if (j == m) {
            cout << A[i++] << " ";
        } else if ((A[i - 1] > B[j] && B[j] > A[i]) || A[i] == B[j]) {
            cout << B[j++] << " ";
        } else {
            cout << A[i++] << " ";
        }
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