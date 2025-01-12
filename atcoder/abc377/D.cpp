/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Many Segments 2

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
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> A(n);
    vector ends(m + 1, vector<int>());
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        A[i] = {x, y};
        ends[y].push_back(i);
    }
    
    ll ans = 0;
    queue<int> q;
    for (int i = 1; i <= m; i++) {
        q.push(i);
        while (!ends[i].empty()) {
            int indx = ends[i].back();
            ends[i].pop_back();
            
            while (!q.empty() && q.front() <= A[indx].first) {
                q.pop();
            }
        }
        ans += q.size();
    }
    
    cout << ans << nl;
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