/*  In the Name of ALLAH, the most gracious, the most merciful  */

// XOUR

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
    map<int, priority_queue<int, vector<int>, greater<int>>> M;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        M[(A[i] >> 2)].push(A[i]);
    }

    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        ans[i] = M[(A[i] >> 2)].top();
        M[(A[i] >> 2)].pop();
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i == n - 1];
    }
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