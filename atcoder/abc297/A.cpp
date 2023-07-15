/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Double Click

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
    vector<int> a(n);
    for (auto &i : a) cin >> i;
    
    int ans = -1;
    for (int i = 1; i < n; i++) {
        if (a[i] - a[i-1] <= d) {
            ans = a[i];
            break;
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