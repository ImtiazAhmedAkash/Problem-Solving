/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Ian Visits Mary

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;

vector<int> dx = {-1, +0, +1, +0, -1, -1, +1, +1};
vector<int> dy = {+0, +1, +0, -1, -1, +1, -1, +1};

void solve() {
    int x, y;
    cin >> x >> y;

    if (gcd(x, y) == 1) {
        cout << 1 << nl;
        cout << x << " " << y << nl;
        return;
    }

    cout << 2 << nl;
    bool ok = false;
    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if (nx < 0 || nx > inf || ny < 0 || ny > inf) continue;
        if (gcd(nx, ny) == 1) {
            cout << nx << " " << ny << nl;
            cout << x << " " << y << nl;
            ok = true;
            break;
        }
    }
    
    assert(ok);
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