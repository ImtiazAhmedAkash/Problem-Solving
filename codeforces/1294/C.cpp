/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Product of Three Numbers

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define N 300005
#define deb(x) cerr << #x << " = " << x << nl
const ll mod = 998244353;

void solve() {
    int n;
    cin >> n;
    vector<int> a;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            a.push_back(i);
            n /= i;
        }
        if (a.size() == 2) {
            a.push_back(n);
            break;
        }
    }
    sort(a.begin(), a.end());
    a.resize(distance(a.begin(), unique(a.begin(), a.end())));
    if (a.size() < 3) {
        cout << "NO" << nl;
    } else {
        cout << "YES" << nl;
        for (auto x : a) cout << x << " ";
        cout << nl;
    }
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