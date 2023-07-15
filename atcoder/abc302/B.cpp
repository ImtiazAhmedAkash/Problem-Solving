/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Find Snuke

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define mod 998244353
#define N 300005
#define deb(x) cerr << #x << " = " << x << nl

int dr[] = {0, 0, -1, 1, -1, 1, -1, 1};
int dc[] = {1, -1, 0, 0, 1, 1, -1, -1};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (auto &i : a) cin >> i;
    string s = "snuke";
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 's') {
                for (int k = 0; k < 8; k++) {
                    queue<pair<int, int>> q;
                    q.push({i+1, j+1});
                    int indx = 1;
                    int nr = i + dr[k], nc = j + dc[k];
                    while(1) {
                        if (nr < 0 || nr >= n || nc < 0 || nc >= m || indx == 5) break;
                        if (a[nr][nc] != s[indx]) break;
                        q.push({nr+1, nc+1});
                        indx++;
                        nr += dr[k];
                        nc += dc[k];
                    }
                    if (indx == 5) {
                        while(!q.empty()) {
                            auto x = q.front();
                            q.pop();
                            cout << x.first << " " << x.second << nl;
                        }
                        return;
                    }
                }
            }
        }
    }
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
    
    return 0;
}