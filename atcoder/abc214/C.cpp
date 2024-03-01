/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Distribution

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
    vector<ll> S(n), T(n);
    for (auto& x : S) cin >> x;
    for (auto& x : T) cin >> x;
    int indx = min_element(T.begin(), T.end()) - T.begin();
    
    vector<ll> ans(n);
    ans[indx] = T[indx];
    for (int i = indx + 1; i < n; i++) {
        ans[i] = min(T[i], ans[i - 1] + S[i - 1]);
    }
    ans[0] = min(T[0], ans[n - 1] + S[n - 1]);
    for (int i = 1; i < indx; i++) {
        ans[i] = min(T[i], ans[i - 1] + S[i - 1]);
    }
    for (auto x : ans) {
        cout << x << nl;
    }
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