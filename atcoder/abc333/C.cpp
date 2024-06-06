/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Repunit Trio

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e15;
const int mod = 998244353;
const int N = 2e5;

void solve() {
    int n;
    cin >> n;
    vector<ll> R;
    ll cur = 1;
    while (cur < INF) {
        R.push_back(cur);
        cur *= 10;
        cur += 1;
    }

    vector<ll> ans;
    for (int i = 0; i < R.size(); i++) {
        for (int j = i; j < R.size(); j++) {
            for (int k = j; k < R.size(); k++) {
                ans.push_back(R[i] + R[j] + R[k]);
            }
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans[n - 1] << nl;
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