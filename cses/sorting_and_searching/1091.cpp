/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Concert Tickets

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

void solve() {
    int n, m;
    cin >> n >> m;
    multiset<int> ms;
    int val;
    for (int i = 0; i < n; i++) {
        cin >> val;
        ms.insert(val);
    }
    for (int i = 0; i < m; i++) {
        cin >> val;
        if (ms.empty() || *(ms.begin()) > val) {
            cout << -1 << nl;
            continue;
        }
        auto it = ms.upper_bound(val);
        it--;
        cout << (*it) << nl;
        ms.erase(it);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}