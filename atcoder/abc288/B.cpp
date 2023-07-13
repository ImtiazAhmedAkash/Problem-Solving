/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Qualification Contest

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

void solve() {
    int n, k;
    cin >> n >> k;
    set<string> s;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        if (i < k) s.insert(str);
    }
    for (auto i : s) cout << i << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}