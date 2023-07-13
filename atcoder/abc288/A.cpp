/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Many A+B Problems

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

void solve() {
    int n;
    cin >> n;
    while (n--) {
        ll a, b;
        cin >> a >> b;
        cout << a + b << nl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}