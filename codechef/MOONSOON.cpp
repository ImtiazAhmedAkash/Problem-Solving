/*  In the Name of ALLAH, the most gracious, the most merciful  */

// MOONSOON - EVacuate to Moon

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define mod 998244353
#define N 300005
#define deb(x) cerr << #x << " = " << x << nl

void solve() {
    ll n, m, h;
    cin >> n >> m >> h;
    vector<ll> car(n), outlet(m);
    for (auto &i : car) cin >> i;
    for (auto &i : outlet) cin >> i;
    
    sort(car.begin(), car.end(), greater<ll>());
    sort(outlet.begin(), outlet.end(), greater<ll>());
    ll ans = 0;
    for (int i = 0; i < min(m, n); i++) {
        ans += min(car[i], outlet[i] * h);
    }
    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}