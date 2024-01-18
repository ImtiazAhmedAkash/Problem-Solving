/*  In the Name of ALLAH, the most gracious, the most merciful  */

// NPRPE - Not Prime Permutation

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
    for (auto &x : A) cin >> x;
    if (n < 3) {
        cout << -1 << nl;
        return;
    }
    vector<int> ans(n);
    int target = (n & 1) ? n + 1 : n;
    for (int i = 0; i < n; i++) {
        if (A[i] == target) {
            ans[i] = target;
        } else {
            ans[i] = target - A[i];
        }
    }
    for (auto x : ans) cout << x << " ";
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