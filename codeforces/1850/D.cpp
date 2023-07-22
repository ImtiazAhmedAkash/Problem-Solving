/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Balanced Round

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
    sort(a.begin(), a.end());
    
    int ok = 1, cnt = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] - a[i - 1] <= k) {
            cnt++; 
            ok = max(ok, cnt);
        } else {
            cnt = 1;
        }
    }
    
    cout << n - ok << nl;
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