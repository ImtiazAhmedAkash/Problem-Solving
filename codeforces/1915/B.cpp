/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Not Quite Latin Square

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
    vector<int> cnt(3);
    for (int i = 0; i < 3; i++) {
        cin >> s;
        for (auto c : s) {
            if (c == '?') continue;
            cnt[c - 'A']++;
        }
    }
    for (int i = 0; i < 3; i++) {
        if (cnt[i] != 3) {
            cout << (char)('A' + i) << nl;
        }
    }
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