/*  In the Name of ALLAH, the most gracious, the most merciful  */

// E - Triple Operations

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
    
    vector<int> M(30);
    int x = 1, y = 1;
    int turn = 0;
    while (y <= r) {
        y *= 3;
        turn++;
        M[turn] = max(0, min(y - 1, r) - max(x, l) + 1);
        x = y;
    }
    
    bool zero = false;
    ll ans = 0;
    for (int i = 1; i < M.size(); i++) {
        if (M[i] == 0) continue;
        if (zero) {
            ans += 1LL * i * M[i];
            continue;
        } 
        
        if (M[i] == 1) {
            M[i + 1]--;
            M[2 * i + 1]++;
            ans += i;
        } else {
            M[2 * i]++;
            ans += 1LL * i * (M[i] - 1);
        }
        zero = true;
    }
    cout << ans << nl;
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