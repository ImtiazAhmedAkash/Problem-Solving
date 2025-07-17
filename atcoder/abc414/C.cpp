/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// C - Palindromic in Both Bases

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
const int mod = 998244353;
const ll N = 1e6;

bool isPalindrome(ll n, int k) {
    string s;
    while (n) {
        s += '0' + (n % k);
        n /= k;
    }
    int m = s.size();
    for (int i = 0; i < m; i++) {
        if (s[i] != s[m - 1 - i]) return false;
    }
    return true;
}

void solve() {
    ll k, r;
    cin >> k >> r;
    
    auto makePalindrome = [&](ll x, bool makeOdd) -> ll {
        string s = to_string(x);
        string t = s;
        if (makeOdd) {
            s.pop_back();
        }
        reverse(s.begin(), s.end());
        t += s;
        x = stoll(t);
        
        if (x <= r && isPalindrome(x, k)) return x;
        return 0;
    };
    
    ll ans = 0;
    for (ll i = 1; i <= min(N, r); i++) {
        ans += makePalindrome(i, true);
        ans += makePalindrome(i, false);
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