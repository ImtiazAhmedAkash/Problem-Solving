/*  In the Name of ALLAH, the most gracious, the most merciful  */

// AtCoder Janken 2

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 1e5;

void solve() {
    int n;
    cin >> n;
    vector<string> A(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> A[i] >> x;
        sum += x;
    }
    sort(A.begin(), A.end());
    cout << A[sum % n] << nl;
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