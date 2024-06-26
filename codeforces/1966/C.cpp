/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Everything Nim

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
    for (auto& x : A) cin >> x;

    sort(A.begin(), A.end());
    A.erase(unique(A.begin(), A.end()), A.end());
    n = A.size();
    if (n == 1 || A[0] != 1) {
        cout << "Alice" << nl;
        return;
    }

    int indx = 0, ans = 0;
    while (indx + 1 < n && A[indx + 1] - A[indx] == 1) {
        indx++;
        ans = !ans;
    }
    if (indx == 0 || indx != n - 1) ans = !ans;
    cout << (ans ? "Bob" : "Alice") << nl;
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