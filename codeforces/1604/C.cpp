/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Di-visible Confusion

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
    string ans = "YES";
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        bool ok = false;
        for (int j = 2; j <= i + 1; j++) {
            if (x % j) {
                ok = true;
                break;
            }
        }
        if (not ok) ans = "NO";
    }
    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}