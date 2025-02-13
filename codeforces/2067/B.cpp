/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// B - Two Large Bags

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

void solve() {
    int n;
    cin >> n;
    multiset<int> A, B;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        A.insert(x);
    }

    while (!A.empty()) {
        int x = *A.rbegin();
        A.erase(A.find(x));

        if (B.empty() || B.find(x) == B.end()) {
            B.insert(x);
        } 
        else if (x == *B.rbegin()) {
            B.erase(x);
        } 
        else if (x == *B.begin()) {
            if (*B.rbegin() == *B.begin() + (int)B.size() - 1) {
                B.erase(--B.end());
            }
            else {
                int y = *(B.lower_bound(x));
                y++;
                while (B.find(y) != B.end()) y++;
                B.insert(y);
            }
        }
    }
    
    cout << (B.empty() ? "Yes" : "No") << nl;
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