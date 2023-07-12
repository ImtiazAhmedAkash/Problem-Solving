/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Rudolph and Tic-Tac-Toe

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define mod 998244353
#define N 300005
#define deb(x) cerr << #x << " = " << x << nl

void solve() {
    vector<string> a(3);
    for (int i = 0; i < 3; i++) {
        cin >> a[i];
    }
    string ans = "DRAW";
    for (int i = 0; i < 3; i++) {
        if (a[i] == "OOO") ans = "O";
        else if (a[i] == "+++") ans = "+";
        else if (a[i] == "XXX") ans = "X";
        else if (a[0][i] == a[1][i] && a[1][i] == a[2][i] && a[1][i] != '.') ans = a[0][i];
    }
    if (a[0][0] == a[1][1] && a[1][1] == a[2][2] && a[1][1] != '.') ans = a[0][0];
    if (a[0][2] == a[1][1] && a[1][1] == a[2][0] && a[1][1] != '.') ans = a[1][1];
    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}