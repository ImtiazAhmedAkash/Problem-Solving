/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Writing a Numeral

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1LL << 62)
#define mod 998244353
#define N 600005
#define deb(x) cerr << #x << " = " << x << nl

void solve() {
    vector<ll> p(N);

    ll mul = 1;
    for (int i = 0; i < N; i++) {
        p[i] = mul % mod;
        mul = (mul * 10) % mod;
    }

    int n;
    cin >> n;

    deque<int> dq;
    dq.push_back(1);
    ll ans = 1;

    while (n--) {
        int x, y;
        cin >> x;
        if (x == 1) {
            cin >> y;
            dq.push_back(y);
            ans = ((ans * 10) + y) % mod;
        } 
        else if (x == 2) {
            y = dq.front();
            dq.pop_front();
            ans = (ans - (y * p[(int)dq.size()])) % mod;
            ans = (ans + mod) % mod;
        } 
        else cout << ans << nl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}
