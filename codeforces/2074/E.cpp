/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// E - Empty Triangle

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
const int N = 2e5 + 5;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int ask(int a, int b, int c) {
    cout << "? " << a << " " << b << " " << c << endl;
    cin >> a;
    return a;
}
void print(int a, int b, int c) {
    cout << "! " << a << " " << b << " " << c << endl;
}

void solve() {
    int n;
    cin >> n;
    
    vector<int> ans = {1, 2, 3};
    while (true) {
        int x = ask(ans[0], ans[1], ans[2]);
        
        if (x == 0) {
            print(ans[0], ans[1], ans[2]);
            return;
        }
        
        int pos = rng() % 3;
        ans[pos] = x;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        solve();
    }
    
    return 0;
}