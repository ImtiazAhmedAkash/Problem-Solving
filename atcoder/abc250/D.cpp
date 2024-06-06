/*  In the Name of ALLAH, the most gracious, the most merciful  */

// 250-like Number

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e15;
const int mod = 998244353;
const int N = 1e6;

vector<bool> isPrime(N + 5, true);
vector<int> P;

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

void solve() {
    ll n;
    cin >> n;
    ll ans = 0;
    for (int i = 0; i < P.size(); i++) {
        ll q = 1LL * P[i] * P[i] * P[i];
        if (n <= q) break;
        ll p = min((ll)P[i] - 1, n / q);
        int cur = upper_bound(P.begin(), P.end(), p) - P.begin();
        ans += cur;
    }
    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    sieve();

    int T = 1;
    for (int t = 1; t <= T; t++) {
        solve();
    }

    return 0;
}