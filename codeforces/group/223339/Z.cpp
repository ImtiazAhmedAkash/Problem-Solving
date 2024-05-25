/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Left Max

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;

void fun(int indx, int mx, vector<int>& A) {
    if (indx == A.size()) return;
    mx = max(mx, A[indx]);
    cout << mx << " ";
    fun(indx + 1, mx, A);
}

void solve() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (auto& x : A) cin >> x;

    fun(0, A[0], A);
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