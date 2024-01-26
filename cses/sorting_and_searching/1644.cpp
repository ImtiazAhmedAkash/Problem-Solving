/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Maximum Subarray Sum II

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
    int n, a, b;
    cin >> n >> a >> b;
    vector<ll> A(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    vector<ll> pref(n + 1);
    partial_sum(A.begin(), A.end(), pref.begin());
    multiset<ll> ms;
    ll ans = -INF;
    for (int i = a; i <= b; i++) {
        ms.insert(pref[i - a]);
        ans = max(ans, pref[i] - *ms.begin());
    }
    for (int i = b + 1; i <= n; i++) {
        ms.erase(ms.find(pref[i - b - 1]));
        ms.insert(pref[i - a]);
        ans = max(ans, pref[i] - *ms.begin());
    }
    cout << ans << nl;
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