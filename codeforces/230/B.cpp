/*  In the Name of ALLAH, the most gracious, the most merciful  */

// T-primes

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define mod 998244353
#define N 1000005
#define deb(x) cerr << #x << " = " << x << nl

vector<bool> prime (N, true);

void sieve() {
    prime[0] = prime[1] = false;
    for (int i = 2; i <= N; i++) {
        if (prime[i]) {
            for (int j = i + i; j <= N; j += i) {
                prime[j] = false;
            }
        }
    }
}

void solve() {
    sieve();
    int n;
    cin >> n;
    while (n--) {
        ll x;
        cin >> x;
        string ans = "NO";
        ll sqx = sqrt(x);
        if (sqx * sqx == x && prime[sqx]) ans = "YES";
        cout << ans << nl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
    
    return 0;
}