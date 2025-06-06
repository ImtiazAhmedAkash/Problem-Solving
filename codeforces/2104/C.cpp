/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// C - Card Game

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "Dbug.h"
#else
#define dbg(...)
#endif

using ll = long long;
constexpr char nl = '\n';

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    set<int> stA, stB;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'A') {
            stA.insert(i + 1);
        } else {
            stB.insert(i + 1);
        }
    }

    bool alice = false;
    for (auto &x : stA) {
        if (x == 1) {
            if (stB.lower_bound(x) != stB.end() && *stB.lower_bound(x) == n) {
                alice = true;
            }
        } 
        else if (x == n) {
            if (stB.find(1) == stB.end()) {
                alice = true;
            }
        } 
        else if (stB.lower_bound(x) == stB.end()) {
            alice = true;
        }
    }

    cout << (alice ? "Alice" : "Bob") << nl;
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