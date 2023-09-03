/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Make Equal With Mod

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
    string ans = "YES";
    bool check = false;
    vector<int> a(n);
    for (auto &x : a) {
        cin >> x;
        if (x == 1) check = true;
    }
    if (check) {
        sort(a.begin(), a.end());
        for (int i = 1; i < n; i++) {
            if (a[i] - a[i - 1] == 1) {
                ans = "NO";
            }
        }
    }
    cout << ans << nl;
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