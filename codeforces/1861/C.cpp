/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Queries for the Array

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int INF = (1 << 30);
const int mod = 998244353;
const int N = 2e5 + 5;

void solve() {
    string s;
    cin >> s;
    vector<vector<bool>> x(2);
    x[0].push_back(false);
    x[1].push_back(true);
    int cur = 0;
    string ans = "YES";
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '+') {
            cur++;
            if (cur > 1) {
                x[0].push_back(true);
                x[1].push_back(x[1].back());
            }
        } else if (s[i] == '-') {
            cur--;
            if (cur > 0) {
                x[0].pop_back();
                x[1].pop_back();
            }
        } else {
            int pos = s[i] - '0';
            if (! x[pos].back()) ans = "NO";
            x[pos].back() = true;
            x[!pos].back() = false;
            if (pos == 1) {
                fill(x[0].begin(), x[0].end(), false);
            }
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