/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Yet Another Permutation Problem

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
    vector<int> ans;
    vector<bool> done(n + 1, false);
    for (int i = 1; i <= n; i++) {
        if (!done[i]) {
            for (int j = i; j <= n; j += j) {
                ans.push_back(j);
                done[j] = true;
            }
        }
    }
    for (auto x : ans) cout << x << " ";
    cout << nl;
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