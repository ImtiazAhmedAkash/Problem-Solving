/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Getting Zero

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 32768;
const int N = 2e5;

void solve() {
    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        
        int ans = inf;
        for (int i = 0; i < 20; i++) {
            for (int j = 0; j < 20; j++) {
                if (((x + i) << j) % mod == 0) {
                    ans = min(ans, i + j);
                }
            }
        }
        cout << ans << " ";
    }
    cout << nl;
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