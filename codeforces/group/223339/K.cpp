/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Max Number

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 1e5;

void fun(vector<int>& A, int indx, int& mx) {
    if (indx == A.size()) {
        cout << mx << nl;
        return;
    }
    mx = max(mx, A[indx]);
    fun(A, indx + 1, mx);
}

void solve() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (auto& x : A) cin >> x;
    int mx = -inf;
    fun(A, 0, mx);
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