/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Mere Array

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
    auto b = a;
    sort(b.begin(), b.end());
    int mini = b.front();
    string ans = "YES";
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i] && gcd(a[i], mini) != mini) {
            ans = "NO";
            break;
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