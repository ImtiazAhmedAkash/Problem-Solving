/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Tiles Comeback

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define mod 998244353
#define N 300005
#define deb(x) cerr << #x << " = " << x << nl

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    string ans = "YES";
    int frst = 0, lst = 0;
    for (int i = 0; i < n; i++) {
        if (frst < k && a[i] == a.front()) frst++;
        else if (frst == k && a[i] == a.back()) lst++;
    }
    
    if (a.front() == a.back() && frst + lst < k) ans = "NO";
    if (a.front() != a.back() && (frst < k || lst < k)) ans = "NO";
    
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