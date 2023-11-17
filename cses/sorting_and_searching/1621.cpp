/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Distinct Numbers

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

void solve() {
    int n;
    cin >> n;
    set<int> s;
    while (n--) {
        int x;
        cin >> x;
        s.insert(x);
    }
    cout << s.size() << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}