/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Nuts

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

void solve() {
    int n;
    cin >> n;
    int ans = 0, val;
    while(n--) {
        cin >> val;
        ans += max(0, val - 10);
    }
    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
    
    return 0;
}