/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Factors of Factorial

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = (1 << 30);
const ll INF = (1LL << 62);
const int mod = 1e9 + 7;
const int N = 1e7 + 5;

void solve() {
    int n;
    cin >> n;
    vector<int> prime;

    auto sieve = [&](int n) {
        vector<bool> isPrime(n + 1, true);
        prime.push_back(2);
        for (int i = 3; i * i <= n; i += 2) {
            if (isPrime[i]) {
                for (int j = i * i; j <= n; j += (i + i)) {
                    isPrime[j] = false;
                }
            }
        }
        for (int i = 3; i <= n; i += 2) {
            if (isPrime[i]) {
                prime.push_back(i);
            }
        }
    };

    sieve(n);
    ll ans = 1;
    for (auto x : prime) {
        int cur = n, cnt = 0;
        while (cur / x) {
            cur /= x;
            cnt += cur;
        }
        ans = (ans * (cnt + 1)) % mod;
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