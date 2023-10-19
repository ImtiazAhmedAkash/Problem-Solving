/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Divide and Equalize

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 1e6 + 5;

vector<int> P;
vector<bool> isPrime(N, true);
void sieve() {
    P.push_back(2);
    for (int i = 3; i * i < N; i += 2) {
        if (isPrime[i]) {
            for (int j = i * i; j < N; j += (i + i)) {
                isPrime[j] = false;
            }
        }
    }
    for (int i = 3; i < N; i += 2) {
        if (isPrime[i]) {
            P.push_back(i);
        }
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (auto &x : A) cin >> x;
    map<int, int> M;
    for (auto x : A) {
        for (int i = 0; i < P.size() && P[i] * P[i] <= x; i++) {
            if (x % P[i] == 0) {
                while (x % P[i] == 0) {
                    x /= P[i];
                    M[P[i]]++;
                }
            }
        }
        if (x != 1) M[x]++;
    }
    string ans = "YES";
    for (auto [a, b] : M) {
        if (b % n) {
            ans = "NO";
            break;
        }
    }
    cout << ans << nl;
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