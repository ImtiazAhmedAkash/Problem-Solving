/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Trailing Zeros

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 60;

void solve() {
    int n;
    cin >> n;
    
    vector<ll> A(N);
    ll cur = 0;
    for (int i = N - 1; ~i; i--) {
        cur |= (1LL << i);
        A[i] = cur;
    }
    ll ans = 0, lst = 0;
    while (n--) {
        int x;
        cin >> x;
        ans |= (1LL << x);
        ans &= A[x];
        while (ans <= lst) {
            ans += (1LL << (x + 1));
        }
        lst = ans;
    }
    cout << ans << nl;
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