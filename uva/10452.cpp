/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Marcus

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;
vector<int> dir = {0, -1, 0, +1};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> A(n);
    int sx = -1, sy = -1;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        if(A[i].find('@') != -1) {
            sx = i;
            sy = A[i].find('@');
        }
    }
    
    vector<string> ans;
    auto bfs = [&](int sx, int sy) {
        string s = "IEHOVA#";
        int indx = 0;
        queue<pair<int, int>> Q;
        Q.push({sx, sy});
        while (!Q.empty()) {
            int ax = Q.front().first;
            int ay = Q.front().second;
            Q.pop();
            for (int i = 0; i + 1 < dir.size(); i++) {
                int nx = ax + dir[i];
                int ny = ay + dir[i + 1];
                if (nx < 0 || ny < 0 || nx >= n || ny >= m || indx == s.size()) continue;
                if (A[nx][ny] == s[indx]) {
                    if (i == 0) ans.push_back("left");
                    else if (i == 1) ans.push_back("forth");
                    else ans.push_back("right");
                    indx++;
                    Q.push({nx, ny});
                }
            }
        } 
    };
    
    bfs(sx, sy);
    for (int i = 0; i < ans.size(); i++) {
        if (i) cout << " ";
        cout << ans[i];
    }
    cout << nl;
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