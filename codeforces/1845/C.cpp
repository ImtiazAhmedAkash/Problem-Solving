/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Strong Password

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int INF = (1 << 30);
const int mod = 998244353;
const int N = 2e5 + 5;

void solve() {
    string s, l, r;
    int m;
    cin >> s >> m >> l >> r;
    string ans = "NO";
    vector<int> pos[10];
    int n = s.size();
    for (int i = 0; i < n; i++) {
        pos[s[i] - '0'].push_back(i);
    }
    int indx = -1;
    for (int i = 0; i < m; i++) {
        int li = l[i] - '0';
        int ri = r[i] - '0';
        int mx = 0;
        for (int j = li; j <= ri; j++) {
            int tmp = upper_bound(pos[j].begin(), pos[j].end(), indx) - pos[j].begin();
            if (tmp == pos[j].size()) tmp = n;
            else tmp = pos[j][tmp];
            mx = max(mx, tmp);
        }
        indx = mx;
        if (indx >= n) {
            ans = "YES";
            break;
        }
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