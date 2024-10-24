/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// LCS on Permutations

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
    vector<int> B(n);
    for (auto &x : B) cin >> x;

    vector<int> pos(n + 1);
    for (int i = 0; i < n; i++) {
        pos[A[i]] = i;
    }

    vector<int> C(n);
    for (int i = 0; i < n; i++) {
        C[i] = pos[B[i]];
    }

    vector<int> dp;
    for (auto &x : C) {
        auto it = lower_bound(dp.begin(), dp.end(), x);
        if (it == dp.end()) {
            dp.push_back(x);
        } else {
            *it = x;
        }
    }

    cout << dp.size() << nl;
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