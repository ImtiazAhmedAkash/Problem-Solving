/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// E - Hierarchical Majority Vote

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
    string s;
    cin >> s;
    
    n = s.size();
    vector<pair<int, int>> A(n); // {majorityElement, minimum operations to change}
    for (int i = 0; i < n; i++) {
        A[i].first = s[i] - '0';
        A[i].second = 1;
    }
    
    while (A.size() != 1) {
        vector<pair<int, int>> B;
        for (int i = 0; i < A.size(); i += 3) {
            if (A[i].first == A[i + 1].first && A[i].first == A[i + 2].first) {
                int op = A[i].second + A[i + 1].second + A[i + 2].second;
                int mxOp = max({A[i].second, A[i + 1].second, A[i + 2].second});
                B.push_back({A[i].first, op - mxOp});
            }
            else if (A[i].first == A[i + 1].first) {
                B.push_back({A[i].first, min(A[i].second, A[i + 1].second)});
            }
            else if (A[i].first == A[i + 2].first) {
                B.push_back({A[i].first, min(A[i].second, A[i + 2].second)});
            }
            else if (A[i + 1].first == A[i + 2].first) {
                B.push_back({A[i + 1].first, min(A[i + 1].second, A[i + 2].second)});
            }
        }
        A = B;
    }
    
    cout << A.front().second << nl;
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