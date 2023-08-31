/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Mex Repetition

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int INF = (1 << 30);
const int mod = 998244353;
const int N = 2e5 + 5;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    ll cur = 0;
    for (auto &x : a) {
        cin >> x;
        cur += x;
    }
    ll total = 1LL * n * (n + 1) / 2;
    int absent = total - cur;
    k = k % (n + 1);
    vector<int> ans;
    if (k == 0) {
        ans = a;
    } else {
        for (int i = n - k + 1; i < n; i++) {
            ans.push_back(a[i]);
        }
        ans.push_back(absent);
        for (int i = 0; i < n - k; i++) {
            ans.push_back(a[i]);
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