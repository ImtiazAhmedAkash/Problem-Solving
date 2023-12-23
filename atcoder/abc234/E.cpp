/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Arithmetic Number

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
    string t(s.size(), '0');
    t.front() = s.front();
    for (char x = t.front(); x <= '9'; x++) {
        string cur = t;
        cur.front() = x;
        for (int diff = -9; diff < 9; diff++) {
            bool ok = true;
            for (int i = 1; i < cur.size(); i++) {
                if (cur[i - 1] + diff > '9' || cur[i - 1] + diff < '0') {
                    ok = false;
                    break;
                }
                cur[i] = cur[i - 1] + diff;
            }
            if (ok && s <= cur) {
                cout << cur << nl;
                return;
            }
        }
    }
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