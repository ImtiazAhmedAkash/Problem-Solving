/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Creating Expression1

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;

int fun(int indx, int sum, int k, vector<int>& A) {
    if (indx == A.size()) {
        return sum == k ? 1 : 0;
    }
    return max(fun(indx + 1, sum + A[indx], k, A), fun(indx + 1, sum - A[indx], k, A));
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (auto& x : A) cin >> x;

    cout << (fun(1, A.front(), k, A) ? "YES" : "NO") << nl;
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