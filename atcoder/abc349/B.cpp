/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Commencement

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
    vector<int> cnt(26, 0);
    for (auto c : s) {
        cnt[c - 'a']++;
    }
    map<int, int> M;
    for (int i = 0; i < 26; i++) {
        if (cnt[i]) {
            M[cnt[i]]++;
        }
    }
    for (auto [x, y] : M) {
        if (y != 2) {
            cout << "No" << nl;
            return;
        }
    }
    cout << "Yes" << nl;
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