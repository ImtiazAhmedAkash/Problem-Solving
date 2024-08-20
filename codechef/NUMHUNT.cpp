/*  In the Name of ALLAH, the most gracious, the most merciful  */

// NUMHUNT - Number Hunt

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;

bool isPrime(ll x) {
    if (x <= 1) return false;
    if (x == 2) return true;
    if (x % 2 == 0) return false;
    for (ll i = 3; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}

void solve() {
    ll n;
    cin >> n;
    vector<ll> ans;
    while (ans.size() != 2) {
        if (isPrime(n)) {
            ans.push_back(n);
        }
        n++;
    }
    cout << ans.front() * ans.back() << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        solve();
    }

    return 0;
}