/*  In the Name of ALLAH, the most gracious, the most merciful  */

// String Formation

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
    deque<char> D;
    for (auto c : s) {
        D.push_back(c);
    }
    int q;
    cin >> q;
    int reversed = 0;
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            reversed ^= 1;
            continue;
        }
        int f;
        char c;
        cin >> f >> c;
        if (f == 1) {
            reversed ? D.push_back(c) : D.push_front(c);
        } else if (f == 2) {
            reversed ? D.push_front(c) : D.push_back(c);
        }
    }
    string ans = "";
    for (auto c : D) ans += c;
    cout << (reversed ? string(ans.rbegin(), ans.rend()) : ans) << nl;
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