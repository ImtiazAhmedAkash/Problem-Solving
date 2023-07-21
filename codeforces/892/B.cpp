/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Wrath

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
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    int dead = n - 1 - a.back();
    int ans = 1;
    for (int i = n - 2; i >= 0; i--) {
        if (i < dead) ans++;
        dead = min(dead, i - a[i]);
    }
    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
    
    return 0;
}