/*  In the Name of ALLAH, the most gracious, the most merciful  */

// K-th Beautiful String

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define mod 998244353
#define N 300005
#define deb(x) cerr << #x << " = " << x << nl

void solve() {
    ll n, k;
    cin >> n >> k;
    string ans = "";
    int a = n - 2, b = 2;
    while (a || b) {
        // Let's say we have, a-times 'a', and b times 'b'.
        // 'total' indicates number of possible string, considering 'a' as the first character. 
        ll total = a;
        if (b == 2) {
            total = 1LL * a * (a + 1) / 2;
        }
        
        if (total < k) {
            ans += 'b';
            k -= total;
            b--;
        } else {
            ans += 'a';
            a--;
        }
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