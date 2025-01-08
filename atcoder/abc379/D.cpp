/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Home Garden

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
    int n;
    cin >> n;
    queue<ll> q;
    ll curT = 0;
    
    while (n--) {
        int op;
        cin >> op;
        if (op == 1) {
            q.push(curT);
        } else if (op == 2) {
            int t;
            cin >> t;
            curT += t;
        } else {
            int h;
            cin >> h;
            int ans = 0;
            while (!q.empty() && curT - q.front() >= h) {
                q.pop();
                ans++;
            }
            cout << ans << nl;
        }
    }
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