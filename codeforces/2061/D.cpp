/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Kevin and Numbers

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;

void solve() {
    int n, m;
    cin >> n >> m;
    multiset<int, greater<int>> A;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        A.insert(x);
    }
    multiset<int, greater<int>> B;
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        B.insert(x);
    }
    
    while (!A.empty() && !B.empty() && B.size() <= A.size()) {
        int mxA = *A.begin();
        int mxB = *B.begin();
        if (mxA == mxB) {
            A.erase(A.begin());
            B.erase(B.begin());
        } else if (mxA < mxB) {
            int x = mxB / 2;
            int y = mxB - x;
            B.erase(B.begin());
            B.insert(x);
            B.insert(y);
        } else {
            break;
        }
    }
    
    cout << ((A.empty() && B.empty()) ? "Yes" : "No") << nl;
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