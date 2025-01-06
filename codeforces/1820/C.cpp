/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Constructive Problem

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
    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        mp[A[i]].push_back(i);
    }
    
    int mex = 0;
    while (mp.count(mex)) mex++;
    
    if (mex == n) {
        cout << "No" << nl;
        return;
    }
    
    mex++;
    if (!mp.count(mex)) {
        cout << "Yes" << nl;
        return;
    }
    
    set<int> st;
    for (int i = 0; i < mex; i++) {
        st.insert(i);
    }
    
    int l = mp[mex].front();
    int r = mp[mex].back();
    for (int i = 0; i < n; i++) {
        if (l <= i && i <= r) continue;
        st.erase(A[i]);
    }
    
    cout << (st.size() <= 1 ? "Yes" : "No") << nl;
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