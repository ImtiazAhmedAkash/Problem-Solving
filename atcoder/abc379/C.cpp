/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Sowing Stones

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
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> A(m);
    for (int i = 0; i < m; i++) {
        cin >> A[i].first;
    }
    ll sum = 0;
    for (int i = 0; i < m; i++) {
        cin >> A[i].second;
        sum += A[i].second;
    }
    
    if (sum != n) {
        cout << -1 << nl;
        return;
    }
    
    sort(A.begin(), A.end());
    
    sum = 0;
    ll ans = 1LL * n * (n + 1) / 2;
    for (auto &[x, y] : A) {
        if (sum < x - 1) {
            cout << -1 << nl;
            return;
        }
        
        sum += y;
        ans -= 1LL * x * y;
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