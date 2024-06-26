/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Array Average

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 1e5;

double fun(vector<int>& A, int i) {
    if (i == A.size()) return 0.0;
    return 1.0 * A[i] / (int)A.size() + fun(A, i + 1);
}

void solve() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (auto& x : A) cin >> x;
    cout << fixed << setprecision(6);
    cout << fun(A, 0) << nl;
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