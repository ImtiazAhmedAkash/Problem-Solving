/*  In the Name of ALLAH, the most gracious, the most merciful  */

// SPCP5 - Monsters

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 1e6;

vector<bool> isPrime(N + 5, true);

void sieve() {
    isPrime[0] = isPrime[1] = 0;
    for (int i = 2; i * i <= N; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= N; j += i) {
                isPrime[j] = false;
            }
        }
    }
}

void solve() {
    int n;
    cin >> n;
    for (int i = 0; (1 << i) - 1 <= n; i++) {
        int dmg = (1 << i) - 1;
        int rem = n - dmg;
        if (rem == 0) {
            cout << i << nl;
            return;
        }
        if (isPrime[rem]) {
            cout << i + 1 << nl;
            return;
        }
    }
    cout << -1 << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    sieve();
    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        solve();
    }

    return 0;
}