/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Standings

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
    vector<pair<pair<ll, ll>, int>> a;
    for (int i = 1; i <= n; i++) {
        ll x, y;
        cin >> x >> y;
        a.push_back({{x, x + y}, i});
    }

    auto comp = [&](pair<pair<ll, ll>, int> x, pair<pair<ll, ll>, int> y) {
        ll one = x.first.first * y.first.second;
        ll two = y.first.first * x.first.second;
        if (one == two) return x.second < y.second;
        return one > two;
    };

    sort(a.begin(), a.end(), comp);
    for (auto &[x, y] : a) cout << y << " ";
    cout << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}