/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Buttons

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int INF = (1 << 30);
const int mod = 998244353;
const int N = 2e5 + 5;

void solve() {
    ll a, b, c;
    cin >> a >> b >> c;
    string ans = "First";
    if ((c & 1) && a < b) {
        ans = "Second";
    } else if ((c % 2 == 0) && a <= b){
        ans = "Second";
    }
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