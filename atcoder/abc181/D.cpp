/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Hachi

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 1000;

void solve() {
    string s;
    cin >> s;
    vector<int> cnt(10);
    for (auto x : s) {
        cnt[x - '0']++;
    }
    for (int i = 8; i <= N; i += 8) {
        string t = to_string(i);
        if ((s.size() == 2 && t.size() < 2) || (s.size() >= 3 && t.size() < 3)) continue;
        vector<int> tmp(10);
        for (auto x : t) {
            tmp[x - '0']++;
        }
        bool ok = true;
        for (int j = 0; j <= 9; j++) {
            if (cnt[j] < tmp[j]) ok = false;
        }
        if (ok) {
            cout << "Yes" << nl;
            return;
        }
    }
    cout << "No" << nl;
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