/*  In the Name of ALLAH, the most gracious, the most merciful  */
 
// Flavors
 
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl
 
const int INF = (1 << 30);
const int mod = 998244353;
const int N = 3e5 + 5;
 
vector<int> f[N + 1];
void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        f[a].push_back(b);
    }
    vector<int> maxi;
    int same_maxi = 0;
    for (int i = 1; i <= n; i++) {
        sort(f[i].begin(), f[i].end(), greater());
        if (!f[i].empty()) maxi.push_back(f[i][0]);
        if (f[i].size() > 1) {
            int tmp = f[i][0] + f[i][1] / 2;
            same_maxi = max(same_maxi, tmp);
        }
    }
    sort(maxi.begin(), maxi.end(), greater<int>());
    int ans = 0;
    if (maxi.size() > 1) ans = maxi[0] + maxi[1];
    cout << max(ans, same_maxi) << nl;
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