/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Hossam and Trainees

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 1e5;

vector<bool> isPrime(N + 5, true);
vector<int> prime;
void precalculate() {
    isPrime[0] = isPrime[1] = false;
    for (ll i = 2; i <= N; i++) {
        if (isPrime[i]) {
            for (ll j = i * i; j <= N; j += i) {
                isPrime[j] = false;
            }
        }
    }

    for (int i = 2; i <= N; i++) {
        if (isPrime[i]) {
            prime.push_back(i);
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (auto &x : A) cin >> x;

    map<int, int> M;
    for (auto &x : A) {
        for (int i = 0; i < prime.size() && x >= prime[i]; i++) {
            if (x % prime[i] == 0) {
                while (x % prime[i] == 0) {
                    x /= prime[i];
                }
                M[prime[i]]++;
            }
        }
        if (x != 1) {
            M[x]++;
        }
    }

    for (auto &[x, y] : M) {
        if (y > 1) {
            cout << "YES" << nl;
            return;
        }
    }

    cout << "NO" << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    precalculate();

    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        solve();
    }

    return 0;
}