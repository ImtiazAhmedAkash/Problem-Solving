/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Array Coloring

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define N 300005
#define deb(x) cerr << #x << " = " << x << nl
const ll mod = 998244353;

void solve() {
    int n;
    cin >> n;
    int sum = 0;
    string ans = "YES";
    while (n--) {
        int x;
        cin >> x;
        sum += x;
    }
    if (sum & 1) ans = "NO";
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