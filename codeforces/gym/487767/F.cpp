/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Good Prime

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 1e7;

vector<bool> isPrime(N + 1, true);
vector<int> P;

void sieve() {
    isPrime[0] = isPrime[1] = false;
    for (int i = 3; i * i <= N; i += 2) {
        if (isPrime[i]) {
            for (int j = i * i; j <= N; j += (i + i)) {
                isPrime[j] = false;
            }
        }
    }
    for (int i = 3; i <= N; i += 2) {
        if (isPrime[i] && isPrime[i - 2] && (i & 1)) {
            P.push_back(i);
        }
    }
}

void solve() {
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        int L = lower_bound(P.begin(), P.end(), l) - P.begin();
        int R = upper_bound(P.begin(), P.end(), r) - P.begin();
        cout << R - L << nl;
    }
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