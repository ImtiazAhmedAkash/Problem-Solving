/*  In the Name of ALLAH, the most gracious, the most merciful  */

// MUH and Cube Walls

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod1 = 1e9 + 7, mod2 = 1e9 + 9;
const int N = 2e5;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int gen_random(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}

vector<pair<int, int>> pwr(N + 5), invPwr(N + 5);
int power(int a, int b, int mod) {
    int ans = 1;
    while (b) {
        if (b & 1) ans = 1LL * ans * a % mod;
        a = 1LL * a * a % mod;
        b /= 2;
    }
    return ans;
}
int p1, p2;
void calculate(int l) {
    p1 = gen_random(l + 5, l + 50);
    p2 = gen_random(l + 51, l + 100);
    pwr[0] = {1, 1};
    for (int i = 1; i <= N; i++) {
        pwr[i].first = 1LL * pwr[i - 1].first * p1 % mod1;
        pwr[i].second = 1LL * pwr[i - 1].second * p2 % mod2;
    }
    int invP1 = power(p1, mod1 - 2, mod1);
    int invP2 = power(p2, mod2 - 2, mod2);
    invPwr[0] = {1, 1};
    for (int i = 1; i <= N; i++) {
        invPwr[i].first = 1LL * invPwr[i - 1].first * invP1 % mod1;
        invPwr[i].second = 1LL * invPwr[i - 1].second * invP2 % mod2;
    }
}

struct Hashing {
    int n;
    vector<pair<int, int>> hash;
    Hashing() {}
    Hashing(vector<int>& s) {
        n = s.size();
        hash.push_back({0, 0});
        for (int i = 0; i < n; i++) {
            pair<int, int> p;
            p.first = (hash[i].first + 1LL * s[i] * pwr[i].first % mod1) % mod1;
            p.second = (hash[i].second + 1LL * s[i] * pwr[i].second % mod2) % mod2;
            hash.push_back(p);
        }
    }
    pair<int, int> get_hash(int l, int r) {
        pair<int, int> ans;
        ans.first = 1LL * (hash[r].first - hash[l - 1].first + mod1) * invPwr[l - 1].first % mod1;
        ans.second = 1LL * (hash[r].second - hash[l - 1].second + mod2) * invPwr[l - 1].second % mod2;
        return ans;
    }
    pair<int, int> get_hash() {
        return get_hash(1, n);
    }
};

void solve() {
    int n, w;
    cin >> n >> w;
    map<int, int> M;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    vector<int> B(w);
    for (int i = 0; i < w; i++) {
        cin >> B[i];
    }

    int id = 1;
    for (int i = 0; i + 1 < n; i++) {
        A[i] = A[i + 1] - A[i];
        if (M.find(A[i]) == M.end()) {
            M[A[i]] = id++;
        }
        A[i] = M[A[i]];
    }
    A.pop_back();
    n--;
    for (int i = 0; i + 1 < w; i++) {
        B[i] = B[i + 1] - B[i];
        if (M.find(B[i]) == M.end()) {
            M[B[i]] = id++;
        }
        B[i] = M[B[i]];
    }
    B.pop_back();
    w--;

    calculate(id);

    Hashing h(A);
    auto hb = Hashing(B).get_hash();

    int ans = 0;
    for (int i = 1; i + w - 1 <= n; i++) {
        if (h.get_hash(i, i + w - 1) == hb) {
            ans++;
        }
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