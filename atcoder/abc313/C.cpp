/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Approximate Equalization 2

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1LL << 62)
#define N 300005
#define deb(x) cerr << #x << " = " << x << nl
const ll mod = 998244353;

void solve() {
    int n;
    cin >> n;
    ll sum = 0;
    vector<ll> a(n);
    for (auto &x : a) {
        cin >> x;
        sum += x;
    }
    ll ans = INF;
    ll avg = sum / n;
    ll add = 0, sub = 0, tmp = 0;
    for (auto &x : a) {
        if (x < avg) add += avg - x;
        else if (x > avg + 1) sub += x - (avg + 1);
    }
    tmp = max(add, sub);
    ans = min(ans, tmp);
    
    add = 0, sub = 0;
    for (auto &x : a) {
        if (x + 1 < avg) add += avg - (x + 1);
        else if (x > avg) sub += x - avg;
    }
    tmp = max(add, sub);
    ans = min(ans, tmp);

    cout << ans << nl;
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