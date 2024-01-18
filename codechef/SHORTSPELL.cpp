/*  In the Name of ALLAH, the most gracious, the most merciful  */

// SHORTSPELL - Spell Shortening

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
    int n;
    cin >> n;
    string s;
    cin >> s;
    int indx = n - 1;
    for (int i = 0; i + 1 < n; i++) {
        if (s[i] > s[i + 1]) {
            indx = i;
            break;
        }
    }
    for (int i = 0; i < n; i++) {
        if (indx == i) continue;
        cout << s[i];
    }
    cout << nl;
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