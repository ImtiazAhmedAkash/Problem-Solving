/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Another Problem About Dividing Numbers

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9 + 10;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 4e4 + 5;

vector<int> P;
vector<bool> isPrime(N, true);

void sieve() {
    P.push_back(2);
    for (int i = 3 ; i * i < N; i += 2) {
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

map<int, int> factorize(int n) {
    map<int, int> mp;
    for (int i = 0; i < P.size() && P[i] * P[i] <= n; i++) {
        if (n % P[i] == 0) {
            while (n % P[i] == 0) {
                mp[P[i]]++;
                n /= P[i];
            }
        }
    }
    if (n != 1) mp[n]++;
    return mp;
}

void solve() {
    int a, b, k;
    cin >> a >> b >> k;
    map<int, int> A = factorize(a);
    map<int, int> B = factorize(b);
    int mn = 0, mx = 0, c = 0, d = 0;
    for (auto [x, y] : A) {
        if (B.find(x) == B.end() || B[x] < y) c = 1;
        mx += y;
    }
    for (auto [x, y] : B) {
        if (A.find(x) == A.end() || A[x] < y) d = 1;
        mx += y;
    }
    mn += c + d;
    if (a == b && a > 1) mn = 2;
    else if (a == b && a == 1) mn = inf;
    string ans = "NO";
    if (k >= mn && k <= mx) ans = "YES";
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