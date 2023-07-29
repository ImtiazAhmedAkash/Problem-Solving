/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Code Parsing

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define mod 998244353
#define N 300005
#define deb(x) cerr << #x << " = " << x << nl

void solve() {
    string s;
    cin >> s;
    int x = 0, y = 0;
    for (auto i : s) {
        if (i == 'x') x++;
        else y++;
    }
    char ans = 'x';
    if (x < y) ans = 'y';
    for (int i = 0; i < abs(x - y); i++) cout << ans;
    cout << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}