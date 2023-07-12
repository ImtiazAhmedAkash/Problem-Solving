/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Rudolf and Snowflakes (simple version)

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define mod 998244353
#define N 300005
#define deb(x) cerr << #x << " = " << x << nl

void solve() {
    int n;
    cin >> n;
    for (int k = 2; k < 1000; k++) {
        int cur = 1 + k + k * k;
        int val = k * k;
        while (cur <= n) {
            if (cur == n) {
                cout << "YES" << nl;
                return;
            }
            val *= k;
            cur += val;
        }
    }
    cout << "NO" << nl;
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