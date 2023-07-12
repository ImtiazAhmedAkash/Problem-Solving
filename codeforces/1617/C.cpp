/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Paprika and Permutation

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
    vector<int> ok(n + 2), not_ok;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x <= n && !ok[x]) ok[x] = 1;
        else not_ok.push_back(x);
    }
    sort(not_ok.begin(), not_ok.end());
    int ans = 0;
    for (int i = 1, indx = 0; i <= n; i++) {
        if (!ok[i]) {
            if ((not_ok[indx] - 1) / 2 < i) {
                ans = -1;
                break;
            }
            ans++, indx++;
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