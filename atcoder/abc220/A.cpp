/*  In the Name of ALLAH, the most gracious, the most merciful  */

//

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    int ans = c * ((a + c - 1) / c);
    if (ans > b) ans = -1;
    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
    
    return 0;
}