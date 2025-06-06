/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Trip to the Olympiad

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
    int l, r;
    cin >> l >> r;
    
    int a = 0, b = 0;
    bool done = false;
    for (int bit = 29; bit >= 0; bit--) {
        if (not done) {
            int lbit = (l >> bit) & 1;
            int rbit = (r >> bit) & 1;
            if (lbit == rbit) {
                a |= (lbit << bit);
                b |= (lbit << bit);
            } else {
                a |= (1 << bit);
                done = true;
            }
        } else {
            b |= (1 << bit);
        }
    }
    
    int c = l;
    while (a == c || b == c) {
        c++;
    }
    
    cout << a << " " << b << " " << c << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        solve();
    }
    
    return 0;
}