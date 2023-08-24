/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Two Round Dances

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define N 300005
#define deb(x) cerr << #x << " = " << x << nl
const ll mod = 998244353;

ll ncr(ll n, ll r) {
    ll res = 1;
    if (n == 0) return 0;
    for (int i = 0; i < r; i++) {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    ll ways_to_choose = ncr(n, n / 2); // chossing people for one round dance
    ll comb = 1;
    // comb represents ways to choose for one round dance
    // In a circular table, the number of ways to arrange (n / 2) people = ((n / 2) - 1)! 
    for (int i = 2; i < n / 2; i++) comb *= i;
    
    // There are two round dances, so total number of ways = ((n / 2) - 1)! * ((n / 2) - 1)!
    comb *= comb;
    // The order doesn't matter, so dividing the comb by 2.
    ll ans = ways_to_choose * comb / 2;
    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    while (t--) {
        solve();
    }
    
    return 0;
}