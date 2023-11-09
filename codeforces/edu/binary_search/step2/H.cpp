/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Hamburgers

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e15;
const int mod = 998244353;
const int N = 2e5 + 5;

void solve() {
    string s;
    cin >> s;
    ll hb, hs, hc;
    cin >> hb >> hs >> hc;
    ll pb, ps, pc, money;
    cin >> pb >> ps >> pc >> money;
    ll nb = 0, ns = 0, nc = 0;
    for (auto x : s) {
        if (x == 'B') nb++;
        else if (x == 'S') ns++;
        else nc++;
    }
    
    auto check = [&](ll mid) {
        ll B = max(0LL, nb * mid - hb);
        ll S = max(0LL, ns * mid - hs);
        ll C = max(0LL, nc * mid - hc);
        ll cost = B * pb + S * ps + C * pc;
        return cost <= money;
    };
    
    ll L = -1, R = INF;
    while (L < R) {
        ll M = L + (R - L + 1) / 2;
        if (check(M)) L = M;
        else R = M - 1;
    }
    cout << R << nl;
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