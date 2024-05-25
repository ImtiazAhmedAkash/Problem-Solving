/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Palindrome Array

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 1e5;

bool fun(vector<int>& A, int i, int j) {
    if (i >= j) return true;
    if (A[i] != A[j]) return false;
    return fun(A, i + 1, j - 1);
}

void solve() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (auto& x : A) cin >> x;
    cout << (fun(A, 0, n - 1) ? "YES" : "NO") << nl;
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