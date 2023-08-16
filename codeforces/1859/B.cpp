/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Olya and Game with Arrays

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define N 300005
#define deb(x) cerr << #x << " = " << x << nl
const ll mod = 998244353;

void solve() {
    int n;
    cin >> n;
    vector<ll> mini, maxi;
    for (int i = 0; i < n; i++) {
        ll m;
        cin >> m;
        vector<ll> b(m);
        for (auto &x : b) cin >> x;
        sort(b.begin(), b.end());
        mini.push_back(b[0]);
        maxi.push_back(b[1]);
    }
    sort(mini.begin(), mini.end());
    sort(maxi.begin(), maxi.end());
    ll ans = mini.front();
    for (int i = 1; i < maxi.size(); i++) ans += maxi[i];
    cout << ans << nl;
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}