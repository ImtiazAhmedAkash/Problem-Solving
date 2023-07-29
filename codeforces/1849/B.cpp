/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Monsters

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define mod 998244353
#define N 300005
#define deb(x) cerr << #x << " = " << x << nl

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> ans;
    vector<pair<int, int>> a;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (x % k == 0) ans.push_back(i);
        else a.push_back({x % k, i});
    }
    
    auto comp = [&] (pair<int, int> x, pair<int, int> y) {
        if (x.first != y.first) return x.first > y.first;
        return x.second < y.second;
    };
    
    sort(a.begin(), a.end(), comp);
    for (int i = 0; i < a.size(); i++) {
        ans.push_back(a[i].second);
    }
    
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