/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Long Sequence

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

void solve() {
    ll n;
    cin >> n;
    vector<ll> v(n);
    ll sum = 0;
    for (auto &i : v) {
        cin >> i;
        sum += i;
    }
    ll x;
    cin >> x;
    ll ans = (x / sum) * n;
    ll rem = x % sum;
    ll i = 0;
    while(rem >= 0) {
        rem -= v[i++];
        ans++;
    }
    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
    
    return 0;
}