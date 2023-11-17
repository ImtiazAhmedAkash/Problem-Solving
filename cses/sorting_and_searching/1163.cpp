/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Traffic Lights

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

void solve() {
    int x, n;
    cin >> x >> n;
    set<int> pos = {0, x};
    multiset<int> diff = {x};
    int val;
    for (int i = 0; i < n; i++) {
        cin >> val;
        pos.insert(val);
        auto it = pos.find(val);
        auto high = pos.upper_bound(val);
        
        diff.insert(*high - *it);
        diff.insert(*it - *(--it));
        diff.erase(diff.find(*high - *it));
        
        cout << *(diff.rbegin()) << ' ';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}