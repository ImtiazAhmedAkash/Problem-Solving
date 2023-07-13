/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Multi Test Cases

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

void solve() {
    int n;
    cin >> n;
    int val, cnt = 0;
    while(n--) {
        cin >> val;
        if (val & 1) cnt++;
    }
    cout << cnt << nl;
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