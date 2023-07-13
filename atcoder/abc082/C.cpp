/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Good Sequence

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

void solve() {
    int n;
    cin >> n;
    map<int, int> m;
    while(n--) {
        int val;
        cin >> val;
        m[val]++;
    }
    int ans = 0;
    for (auto &i : m) {
        if (i.first > i.second) ans += i.second;
        else if (i.first < i.second) ans += (i.second - i.first);
    }
    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
    
    return 0;
}