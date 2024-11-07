/*  In the Name of ALLAH, the most gracious, the most merciful  */

// P3149 - Easy Subarray Sum

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
    int cnt = 0;
    for (auto &x : A) {
        cin >> x;
    }

    int i = 0;
    while (i < n && A[i] <= 0) i++;
    int j = n - 1;
    while (j >= 0 && A[j] <= 0) j--;

    int ans = 0;
    while (i <= j) {
        if (A[i] < 0) ans++;
        i++;
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