/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// ARC Division

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;

void solve() {
    int n, r;
    cin >> n >> r;
    while (n--) {
        int d, a;
        cin >> d >> a;
        if (d == 1 && 1600 <= r && r <= 2799) {
            r += a;
        } else if (d == 2 && 1200 <= r && r <= 2399) {
            r += a;
        }
    }
    
    cout << r << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T = 1;
    for (int t = 1; t <= T; t++) {
        solve();
    }
    
    return 0;
}