/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Assembly via Minimums

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
    int limit = n * (n - 1) / 2;
    for (int i = 0; i < limit; i++) {
        int x;
        cin >> x;
        a.push_back(x);
    }
    sort(a.begin(), a.end());
    vector<int> ans;
    
    int x = n - 1;
    for (int i = n - 2; x && i < a.size(); i += x) {
        ans.push_back(a[i]);
        x--;
    }
    
    ans.push_back((int) 1e9);
    for (auto &x : ans) cout << x << " ";
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