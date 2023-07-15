/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Treasure Chest

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define mod 998244353
#define N 2005
#define deb(x) cerr << #x << " = " << x << nl

void solve() {
    int n;
    string s, ans = "out";
    cin >> n >> s;
    int x = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '|') x = !x;
        if (s[i] == '*' && x) ans = "in";
    }
    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}