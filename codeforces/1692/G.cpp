/*  In the Name of ALLAH, the most gracious, the most merciful  */

// 2^Sort

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
    int n, k;
    cin >> n >> k;
    vector<int> A(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    vector<int> pref(n + 1);
    for (int i = 2; i <= n; i++) {
        if (A[i - 1] >= A[i] * 2) pref[i] = 1;
    }
    partial_sum(pref.begin(), pref.end(), pref.begin());
    int ans = 0;
    for (int i = 1; i <= n - k; i++) {
        if (pref[i + k] - pref[i] == 0) {
            ans++;
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