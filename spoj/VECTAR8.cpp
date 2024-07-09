/*  In the Name of ALLAH, the most gracious, the most merciful  */

// VECTAR8 - Primal Fear

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
vector<int> scaryPrime(N + 5);

void sieve() {
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= N; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= N; j += i) {
                isPrime[j] = false;
            }
        }
    }

    for (int i = 2; i <= N; i++) {
        scaryPrime[i] = scaryPrime[i - 1];
        if (isPrime[i]) {
            string s = to_string(i);
            if (s.find('0') != -1) continue;

            string t;
            bool ok = true;
            for (int i = (int)s.size() - 1; i >= 0; i--) {
                t = s[i] + t;
                if (!isPrime[stoi(t)]) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                scaryPrime[i]++;
            }
        }
    }
}

void solve() {
    int n;
    cin >> n;
    cout << scaryPrime[n] << nl;
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
