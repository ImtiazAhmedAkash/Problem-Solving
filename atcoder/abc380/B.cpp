/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Hurdle Parsing

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
    string s;
    cin >> s;
    
    int n = s.size();
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (s[i] == '-') {
            int cnt = 0;
            int j = i;
            while (j < n && s[i] == s[j]) {
                cnt++, j++;
            }
            ans.push_back(cnt);
            i = j - 1;
        }
    }
    
    for (auto &x : ans) {
        cout << x << " ";
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