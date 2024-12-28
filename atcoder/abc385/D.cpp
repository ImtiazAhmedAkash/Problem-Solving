/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Santa Claus 2

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
    ll n, m, x, y;
    cin >> n >> m >> x >> y;
    
    map<ll, set<ll>> col, row;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        row[a].insert(b);
        col[b].insert(a);
    }
    
    int ans = 0;
    if (row[x].find(y) != row[x].end()) {
        ans++;
        row[x].erase(y);
        col[y].erase(x);
    }
    
    for (int i = 0; i < m; i++) {
        char c;
        int d;
        cin >> c >> d;
        ll px = x, py = y;
        if (c == 'U') y += d;
        if (c == 'D') y -= d;
        if (c == 'L') x -= d;
        if (c == 'R') x += d;
        
        ll cx = x, cy = y;
        if (px > cx || py > cy) {
            swap(px, cx);
            swap(py, cy);
        }
        
        if (c == 'U' || c == 'D') {
            vector<int> A;
            auto it = row[x].lower_bound(py);
            for (it; it != row[x].end() && *it <= cy; it++) {
                A.push_back(*it);
                ans++;
            }
            while (!A.empty()) {
                row[x].erase(A.back());
                col[A.back()].erase(x);
                A.pop_back();
            }
        } else {
            vector<int> A;
            auto it = col[y].lower_bound(px);
            for (it; it != col[y].end() && *it <= cx; it++) {
                A.push_back(*it);
                ans++;
            }
            while (!A.empty()) {
                col[y].erase(A.back());
                row[A.back()].erase(y);
                A.pop_back();
            }
        }
        
    }
    
    cout << x << " " << y << " " << ans << nl;
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