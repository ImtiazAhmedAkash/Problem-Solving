/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Jiro

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
    char ab, ac, bc;
    cin >> ab >> ac >> bc;
    int a = 0, b = 0, c = 0;
    if (ab == '<') b++;
    else a++;
    if (ac == '<') c++;
    else a++;
    if (bc == '<') c++;
    else b++;
    char ans = 'A';
    if (b == 1) ans = 'B';
    if (c == 1) ans = 'C';
    cout << ans << nl;
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