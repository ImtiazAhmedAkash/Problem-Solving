/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Shift vs CapsLock

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1LL << 62)
#define mod 998244353
#define N 300005
#define deb(x) cerr << #x << " = " << x << nl

ll x, y, z;
ll dp[N][2];
vector<ll> a;

ll f(int indx, int on) {
    if (indx == (int) a.size()) return 0LL;
    
    if (dp[indx][on] != -1) return dp[indx][on];
    
    ll res = INF;
    
    // capital
    if (indx & 1) {
        if (on) {
            res = min(res, a[indx] * x + f(indx + 1, 1));
            res = min(res, z + a[indx] * y + f(indx + 1, 0));
        }
        else {
            res = min(res, a[indx] * y + f(indx + 1, 0));
            res = min(res, a[indx] * x + z + f(indx + 1, 1));
        }
    }
    
    // small
    else {
        if (!on) {
            res = min(res, a[indx] * x + f(indx + 1, 0));
            res = min(res, z + a[indx] * y + f(indx + 1, 1));
        }
        else {
            res = min(res, a[indx] * y + f(indx + 1, 1));
            res = min(res, a[indx] * x + z + f(indx + 1, 0));
        }
    }
    
    return dp[indx][on] = res;
}

void solve() {
    cin >> x >> y >> z;
    string s;
    cin >> s;

    if (s.front() == 'A') a.push_back(0);

    ll cnt = 1;
    for (int i = 0; i < s.size(); i++) {
        if (i == s.size() - 1 || s[i] != s[i + 1]) {
            a.push_back(cnt);
            cnt = 1;
        } else
            cnt++;
    }
    
    memset(dp, -1, sizeof dp);
    ll ans = f(0, 0);
    
    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
