/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Vacation Together

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define mod 998244353
#define N 300005
#define deb(x) cerr << #x << " = " << x << nl

void solve() {
    int n, d;
    cin >> n >> d;
    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = 0, tmp = 0;
    for (int i = 0; i < d; i++) {
        bool ok = true;
        for (int j = 0; j < n; j++) {
            if (a[j][i] == 'x') {
                ok = false;
                break;
            }
        }
        if (ok) {
            tmp++;
            ans = max(ans, tmp);
        } else {
            tmp = 0;
        }
    }
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