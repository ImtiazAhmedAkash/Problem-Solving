/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Nine

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define mod 998244353
#define N 300005
#define deb(x) cerr << #x << " = " << x << nl

void solve() {
    int a, b;
    cin >> a >> b;
    string ans = "No";
    if ((b == a + 1) && (a % 3 != 0)) {
        ans = "Yes";
    }
    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
    
    return 0;
}