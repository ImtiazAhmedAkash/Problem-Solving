/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Minimize Distance

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define mod 998244353
#define N 300005
#define deb(x) cerr << #x << " = " << x << nl

void solve() {
    int n, k;
    cin >> n >> k;
    vector<ll> pos, neg;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        if (x > 0) pos.push_back(x);
        else if (x < 0) neg.push_back(-x);
    }
    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end());
    
    auto calculate_distance = [&] (vector<ll>& a, vector<ll>& b) {
        ll dist = 0;
        for (int i = (int) a.size() - 1; i >= 0; i -= k) {
            dist += (2 * a[i]);
        }
        if (!b.empty()) dist += b.back();
        for (int i = (int) b.size() - 1 - k; i >= 0; i -= k) {
            dist += (2 * b[i]);
        }
        return dist;
    };
    
    ll ans = min(calculate_distance(pos, neg), calculate_distance(neg, pos));
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