/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Dash

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define mod 998244353
#define N 300005
#define deb(x) cerr << #x << " = " << x << nl

void solve() {
    int n, m, h, k;
    cin >> n >> m >> h >> k;
    string s;
    cin >> s;
    
    map<pair<int, int>, int> mp;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        mp[{a, b}] = 1;
    }
    
    int x = 0, y = 0;
    for (auto i : s) {
        if (i == 'R') x++;
        else if (i == 'L') x--;
        else if (i == 'U') y++;
        else y--;
        
        h--;
        if (h < 0) {
            cout << "No" << nl;
            return;
        }
        if (mp.find({x, y}) != mp.end() && h < k) {
            h = k;
            mp.erase({x, y});
        }
    }
    cout << "Yes" << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
    
    return 0;
}