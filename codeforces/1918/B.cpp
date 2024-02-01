/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Minimize Inversions

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
    vector<int> A(n), B(n);
    for (auto &x : A) cin >> x;
    for (auto &x : B) cin >> x;
    vector<pair<int, int>> C(n);
    for (int i = 0; i < n; i++) {
        C[i] = {A[i] + B[i], i};
    }
    sort(C.begin(), C.end());
    for (int i = 0; i < n; i++) {
        cout << A[C[i].second] << " ";
    }
    cout << nl;
    for (int i = 0; i < n; i++) {
        cout << B[C[i].second] << " ";
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