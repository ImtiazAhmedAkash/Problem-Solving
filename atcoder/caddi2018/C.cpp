/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Product and GCD

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 1e6;

vector<int> P;
vector<bool> isPrime(N + 5, true);

void sieve() {
    P.push_back(2);
    for (int i = 3; i * i <= N; i += 2) {
        if (isPrime[i]) {
            for (int j = i * i; j <= N; j += (i + i)) {
                isPrime[j] = false;
            }
        }
    }
    for (int i = 3; i <= N; i += 2) {
        if (isPrime[i]) {
            P.push_back(i);
        }
    }
}

ll power(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res *= a;
        a *= a;
        b /= 2;
    }
    return res;
}

void solve() {
    ll n, p;
    cin >> n >> p;

    if (p == 1) {
        cout << 1 << nl;
        return;
    }

    sieve();
    map<ll, int> M;
    for (int i = 0; i < P.size() && 1LL * P[i] * P[i] <= p; i++) {
        while (p % P[i] == 0) {
            M[P[i]]++;
            p /= P[i];
        }
    }
    if (p != 1) M[p]++;

    ll ans = 1;
    for (auto [x, y] : M) {
        ans *= power(x, (y / n));
    }
    cout << ans << nl;
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