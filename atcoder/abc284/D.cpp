/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Happy New Year 2023

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

void solve() {
    ll n;
    cin >> n;
    ll q = 2;
    while (n % q != 0) q++;
    ll p = sqrt(n / q);
    if (p * p != (n / q)) {
        p = q;
        q = n / (p * p);
    }
    cout << p << " " << q;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
        cout << nl;
    }

    return 0;
}