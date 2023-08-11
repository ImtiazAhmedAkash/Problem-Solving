/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Dalton the Teacher

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define mod 998244353
#define N 300005
#define deb(x) cerr << #x << " = " << x << nl

void solve() {
    int n;
    cin >> n;
    int same = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (x == i) same++;
    }
    cout << (same + 1) / 2 << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}