/*  In the Name of ALLAH, the most gracious, the most merciful  */

// To My Critics

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define mod 998244353
#define N 300005
#define deb(x) cerr << #x << " = " << x << nl

void solve() {
    vector<int> a(3);
    for (auto &x : a) cin >> x;
    sort(a.begin(), a.end());
    string ans = "YES";
    if (a[1] + a[2] < 10) ans = "NO";
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