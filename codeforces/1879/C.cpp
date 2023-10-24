/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Make it Alternating

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;

vector<ll> F(N + 5);

void factorial() {
    ll fact = 1;
    F[0] = 1;
    for (int i = 1; i <= N; i++) {
        fact = (fact * i) % mod;
        F[i] = fact;
    }
}

void solve() {
    string s;
    cin >> s;
    ll ans = 0, ways = 1;
    for (int i = 0; i + 1 < s.size(); i++) {
        if (s[i] == s[i + 1]) {
            int cnt = 1, j = i + 1;
            while (j < s.size() && s[i] == s[j]) {
                cnt++, j++;
            }
            i = j - 1;
            ans += cnt - 1;
            ways = (ways * cnt) % mod;
        }
    }
    ways = (ways * F[ans]) % mod;
    cout << ans << " " << ways << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    factorial();
    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        solve();
    }
    
    return 0;
}