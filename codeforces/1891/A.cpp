/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Sorting with Twos

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
    string ans = "YES";
    for (int i = 0; i + 1 < n; i++) {
        if (A[i] > A[i + 1] && __builtin_popcount(i + 1) != 1) {
            ans = "NO";
        }
    }
    cout << ans << nl;
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