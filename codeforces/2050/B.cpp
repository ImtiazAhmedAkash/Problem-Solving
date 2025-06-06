/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Transfusion

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;

void solve() {
    int n;
    cin >> n;
    ll even_sum = 0, odd_sum = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (i & 1) {
            odd_sum += x;
        } else {
            even_sum += x;
        }
    }
    
    if (n == 1) {
        cout << "YES" << nl;
        return;
    }
    
    if ((odd_sum + even_sum) % n) {
        cout << "NO" << nl;
        return;
    }
    
    int even = n / 2;
    int odd = n - even;
    ll target = (odd_sum + even_sum) / n;
    cout <<  (even * target == even_sum && odd * target == odd_sum ? "YES" : "NO") << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        solve();
    }
    
    return 0;
}