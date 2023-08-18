/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Game on Permutation

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int INF = (1 << 30);
const int mod = 998244353;
const int N = 2e5 + 5;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    set<int> win;
    int mini = a.front();
    for (int i = 1; i < n; i++) {
        if (a[i] > mini && (win.empty() || *(win.begin()) > a[i])) {
            win.insert(a[i]);
        }
        mini = min(a[i], mini);
    }
    cout << win.size() << nl;
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