/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Trick Taking

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define mod 998244353
#define N 2005
#define deb(x) cerr << #x << " = " << x << nl

void solve() {
    int n, t;
    cin >> n >> t;
    vector<int> c(n);

    bool ok = false;
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        if (c[i] == t) ok = true;
    }

    if (!ok) t = c[0];

    int max_rank = -1, ans;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (c[i] == t && max_rank < x) {
            max_rank = x;
            ans = i + 1;
        }
    }

    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}