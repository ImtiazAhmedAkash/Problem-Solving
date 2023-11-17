/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Apartments

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> va(n), vb(m);
    for (auto &i : va) cin >> i;
    for (auto &i : vb) cin >> i;
    sort(va.begin(), va.end());
    sort(vb.begin(), vb.end());
    int ans = 0, i = 0, j = 0;
    while (i < n && j < m) {
        if (vb[j] < va[i] - k)
            j++;
        else if (vb[j] > va[i] + k)
            i++;
        else {
            ans++;
            j++, i++;
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