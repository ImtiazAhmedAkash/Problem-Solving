/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// D - Object Identification

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

int ask(int x, int y) {
    cout << "? " << x << " " << y << endl;
    int z;
    cin >> z;
    return z;
}

void print(char ch) {
    cout << "! " << ch << endl;
}

void solve() {
    int n;
    cin >> n;
    set<int> st;
    vector<int> A(n + 1);
    for (int i = 1; i <= n; i++) {
        st.insert(i);
    }
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        st.erase(A[i]);
    }
    
    if (st.empty()) {
        int pos1 = -1, posn = -1;
        for (int i = 1; i <= n; i++) {
            if (A[i] == 1) pos1 = i;
            if (A[i] == n) posn = i;
        }
        int x = ask(pos1, posn);
        int y = ask(posn, pos1);
        if (x == y && x >= n - 1) {
            print('B');
        }
        else {
            print('A');
        }
    }
    else {
        int a = *st.begin();
        int b = (a == 1 ? 2 : 1);
        if (ask(a, b) == 0) {
            print('A');
        }
        else {
            print('B');
        }
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