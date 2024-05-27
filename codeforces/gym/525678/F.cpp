/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Again Prime

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 3e6;

void solve() {
    int a, b;
    cin >> a >> b;
    if (a > b) swap(a, b);

    vector<int> P;
    vector<bool> isPrime(N + 5, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= N; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= N; j += i) {
                isPrime[j] = false;
            }
        }
    }
    for (int i = a; i <= b; i++) {
        if (isPrime[i]) {
            P.push_back(i);
        }
    }

    int ans = 0;
    int n = P.size();
    for (int mask = 1; mask < (1 << n); mask++) {
        int sum = 0;
        for (int bit = __lg(mask); bit >= 0; bit--) {
            if (mask & (1 << bit)) {
                sum += P[bit];
            }
        }
        if (isPrime[sum]) ans++;
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