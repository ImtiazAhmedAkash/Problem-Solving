/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Round-Robin Tournament

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;

void solve() {
    int n;
    cin >> n;
    vector<string> A(n);
    for (int i = 0; i < n; i++) cin >> A[i];
    
    auto comp = [&](pair<int, int> x, pair<int, int> y) {
        if (x.first == y.first) return x.second < y.second;
        return x.first > y.first;
    };
    
    vector<pair<int, int>> ans(n);
    for (int i = 0; i < n; i++) {
        int score = 0;
        for (auto x : A[i]) {
            score += (x == 'o');
        }
        ans[i] = {score, i};
    }
    
    sort(ans.begin(), ans.end(), comp);
    for (auto [a, b] : ans) {
        cout << b + 1 << " ";
    }
    cout << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    for (int t = 1; t <= T; t++) {
        solve();
    }
    
    return 0;
}