/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Number into Sequence

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define mod 998244353
#define N 300005
#define deb(x) cerr << #x << " = " << x << nl

void solve() {
    ll n, tmp;
    cin >> n;
    tmp = n;
    map<ll, int> cnt;
    for (ll i = 2; i * i <= tmp; i++) {
        if (tmp % i == 0) {
            while (tmp % i == 0) {
                cnt[i]++;
                tmp /= i;
            }
        }
    }
    if (tmp > 1) cnt[tmp]++;
    
    ll maxi = 0, max_freq = 0;
    for (auto x : cnt) {
        if (x.second > max_freq) {
            maxi = x.first;
            max_freq = x.second;
        }
    }
    
    vector<ll> ans;
    tmp = 1;
    for (int i = 1; i < max_freq; i++) {
        ans.push_back(maxi);
        tmp *= maxi;
    }
    if (tmp != n) ans.push_back(n / tmp);
    
    cout << ans.size() << nl;
    for (auto x : ans) cout << x << " ";
    cout << nl;
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