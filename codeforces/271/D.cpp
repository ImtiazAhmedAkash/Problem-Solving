/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Good Substrings

#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod1 = 1e9 + 7, mod2 = 1e9 + 9;
const int N = 1500;

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
    int p1 = gen_random(151, 200);
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
    string s;
    vector<pair<int, int>> hash;
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

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(pair<int, int> p) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        uint64_t first_hash = splitmix64(p.first + FIXED_RANDOM);
        uint64_t second_hash = splitmix64(p.second + FIXED_RANDOM);
        return first_hash ^ (second_hash << 1);
    }
};

void solve() {
    string s, t;
    cin >> s >> t;
    int k;
    cin >> k;

    Hashing h(s);

    gp_hash_table<pair<int, int>, int, custom_hash> M;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        int bad = 0;
        for (int j = i; j < n; j++) {
            if (t[s[j] - 'a'] == '0') {
                bad++;
            }
            if (bad <= k) {
                M[h.get_hash(i + 1, j + 1)]++;
            } else {
                break;
            }
        }
    }

    cout << M.size() << nl;
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