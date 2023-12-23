/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Five, Five Everywhere

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 55555;

vector<bool> isPrime(N, true);

void sieve() {
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= N; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j < N; j += i) {
                isPrime[j] = false;
            }
        }
    }
}

void solve() {
    sieve();
    int n;
    cin >> n;
    for (int i = 1; i < N && n; i += 10) {
        if (isPrime[i]) {
            cout << i << " ";
            n--;
        }
    }
    cout << nl;
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