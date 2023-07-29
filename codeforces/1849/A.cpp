/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Morning Sandwich

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define mod 998244353
#define N 300005
#define deb(x) cerr << #x << " = " << x << nl

void solve() {
    int b, c, h;
    cin >> b >> c >> h;
    b = min(b, c + h + 1);
    cout << (b + b - 1) << nl;
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