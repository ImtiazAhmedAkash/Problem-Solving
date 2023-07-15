/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Almost Equal

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define mod 998244353
#define N 300005
#define deb(x) cerr << #x << " = " << x << nl

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (auto &i : a) cin >> i;

    sort(a.begin(), a.end());
    do {
        bool ok = true;
        for (int i = 0; i + 1 < n; i++) {
            int cnt = 0;
            for (int j = 0; j < m; j++) {
                if (a[i][j] != a[i + 1][j]) cnt++;
            }
            if (cnt > 1) {
                ok = false;
                break;
            }
        }
        if (ok) {
            cout << "Yes" << nl;
            return;
        }
    } while (next_permutation(a.begin(), a.end()));

    cout << "No" << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}