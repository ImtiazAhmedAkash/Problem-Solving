/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// D - Simple Permutation

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
const int N = 1e5 + 5;

vector<bool> isPrime(N + 5, true);
vector<int> prime;
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
        if (isPrime[i]) {
            prime.push_back(i);
        }
    }
}

void solve() {
    int n;
    cin >> n;
    
    auto it = lower_bound(prime.begin(), prime.end(), n / 2);
    int cur = *it;
    int need = max(0, (n / 3) - 1);
    set<int> st;
    for (int i = 1; i <= n; i++) {
        st.insert(i);
    }
    
    vector<int> ans;
    ans.push_back(cur);
    st.erase(cur);
    need--;
    
    for (int i = 1; need > 0; i++, need--) {
        ans.push_back(cur - i);
        st.erase(cur - i);
        ans.push_back(cur + i);
        st.erase(cur + i);
    }
    
    while (!st.empty()) {
        ans.push_back(*st.begin());
        st.erase(st.begin());
    }
    
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i + 1 == n];
    }
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