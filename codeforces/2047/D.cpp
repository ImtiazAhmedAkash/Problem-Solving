/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Move Back at a Cost

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
    int n;
    cin >> n;
    vector<int> A(n);
    for (auto &x : A) cin >> x;

    vector<pair<int, int>> stk;
    for (int i = 0; i < n; i++) {
        while (!stk.empty() && stk.back().first > A[i]) {
            stk.pop_back();
        }
        stk.push_back({A[i], i});
    }

    set<int> st;
    for (int i = 0; i < stk.size(); i++) {
        st.insert(stk[i].second);
    }

    vector<pair<int, int>> B;
    for (int i = 0; i < n; i++) {
        if (st.find(i) == st.end()) {
            B.push_back({A[i], i});
        }
    }

    sort(B.begin(), B.end());
    
    while (!stk.empty() && !B.empty() && stk.back().first > B.front().first + 1) {
        B.push_back(stk.back());
        stk.pop_back();
    }
    
    sort(B.begin(), B.end());
    
    for (int i = 0; i < B.size(); i++) {
        int mx = max(stk.back().first, B[i].first + 1);
        stk.push_back({mx, B[i].second});
    }

    for (auto &[x, y] : stk) {
        cout << x << " ";
    }
    cout << nl;
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