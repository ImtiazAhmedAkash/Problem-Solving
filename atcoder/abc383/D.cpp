/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// 9 Divisors

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e6;

vector<int> spf(N + 5);

void sieve() {
    iota(spf.begin(), spf.end(), 0);
    
    for (int i = 2; i <= N; i++) {
        if (spf[i] == i) {
            for (int j = i; j <= N; j += i) {
                spf[j] = min(i, spf[j]);
            }
        }
    }
}

void solve() {
    ll x;
    cin >> x;

    int ans = 0;

    auto good = [&](ll val) -> bool {
        map<int, int> mp;
        while (val != 1) {
            mp[spf[val]]++;
            val /= spf[val];
            if (mp.size() > 2) return false;
        }
        
        if (mp.size() == 1 && (*mp.begin()).second == 4) return true;
        
        if (mp.size() != 2) return false;
        
        for (auto &[x, y] : mp) {
            if (y != 1) return false;
        }
        
        return true;
    };

    for (ll i = 2; i * i <= x; i++) {
        if (good(i)) {
            ans++;
        }
    }

    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    sieve();

    int T = 1;
    for (int t = 1; t <= T; t++) {
        solve();
    }

    return 0;
}