/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Rudolf and the Another Competition

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define mod 998244353
#define N 300005
#define deb(x) cerr << #x << " = " << x << nl

void solve() {
    ll n, m, h;
    cin >> n >> m >> h;
    vector<pair<ll, ll>> result;
    pair<ll, ll> rudolf;
    for (int i = 0; i < n; i++) {
        vector<ll> task(m);
        for (auto &x : task) cin >> x;
        sort(task.begin(), task.end());

        ll penalty = 0, solve = 0, time = 0;
        for (int i = 0; i < m; i++) {
            if (time + task[i] > h) break;
            time += task[i];
            penalty += time;
            solve++;
        }

        if (i == 0) rudolf = {solve, penalty};
        result.push_back({solve, penalty});
    }

    auto comp = [&](pair<ll, ll> x, pair<ll, ll> y) {
        if (x.first != y.first) return x.first > y.first;
        return x.second < y.second;
    };

    sort(result.begin(), result.end(), comp);
    int ans = 0;
    for (int i = 0; i < result.size(); i++) {
        if (result[i] == rudolf) {
            ans = i + 1;
            break;
        }
    }
    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}