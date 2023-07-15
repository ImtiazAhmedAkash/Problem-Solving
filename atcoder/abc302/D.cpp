/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Impartial Gift

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define mod 998244353
#define N 300005
#define deb(x) cerr << #x << " = " << x << nl

void solve() {
    ll n, m, d;
    cin >> n >> m >> d;
    
    vector<ll> a(n), b(m);
    for (auto &i : a) cin >> i;
    for (auto &i : b) cin >> i;
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    ll ans = -1;
    
    int x = n-1, y = m-1;
    while(x >= 0 && y >= 0) {
        if (llabs(a[x] - b[y]) <= d) {
            ans = a[x] + b[y];
            break;
        }
        if (a[x] > b[y]) x--;
        else y--;
    }
    
    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
    
    return 0;
}