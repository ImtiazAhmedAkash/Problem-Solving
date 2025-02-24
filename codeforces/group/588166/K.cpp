/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// K - Palindrome Master

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "Dbug.h"
#else
#define dbg(...)
#endif

using ll = long long;
constexpr char nl = '\n';

const int inf = 1e9;
const ll INF = 1e18;
const int mod1 = 1e9 + 7, mod2 = 1e9 + 9;
const int N = 5000;

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
void precalculate() {
    int p1 = gen_random(150, 200);
    int p2 = gen_random(201, 300);
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
    string s;                     // 0 - indexed
    vector<pair<int, int>> hash;  // 1 - indexed
    Hashing() {}
    Hashing(string _s) {
        n = _s.size();
        s = _s;
        hash.push_back({0, 0});
        for (int i = 0; i < n; i++) {
            pair<int, int> p;
            p.first = (hash[i].first + 1LL * s[i] * pwr[i].first % mod1) % mod1;
            p.second = (hash[i].second + 1LL * s[i] * pwr[i].second % mod2) % mod2;
            hash.push_back(p);
        }
    }
    pair<int, int> get_hash(int l, int r) {  // 1 - indexed
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
    string s;
    cin >> s;
    int n = s.size();
    
    Hashing frward(s);
    reverse(s.begin(), s.end());
    Hashing bckward(s);
    
    vector pref(n + 5, vector<ll>(n + 5, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            if (frward.get_hash(i, j) == bckward.get_hash(n - j + 1, n - i + 1)) {
                pref[i][j] = 1;
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            pref[i][j] = pref[i][j] + pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
        }
    }
    
    int q;
    cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y;
        cout << pref[y][y] - pref[y][x - 1] - pref[x - 1][y] + pref[x - 1][x - 1] << nl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    precalculate();
    
    int T = 1;
    for (int t = 1; t <= T; t++) {
        solve();
    }
    
    return 0;
}