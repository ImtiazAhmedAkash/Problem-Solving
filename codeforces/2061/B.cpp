/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Kevin and Geometry

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
    map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    
    vector<int> two;
    set<int> st;
    for (auto &[x, y] : cnt) {
        if (y >= 4) {
            for (int i = 0; i < 4; i++) {
                cout << x << " ";
            }
            cout << nl;
            return;
        }
        if (y == 3) {
            st.insert(x);
            two.push_back(x);
        }
        else if (y == 2) {
            two.push_back(x);
        } else {
            st.insert(x);
        }
    }
    
    if (two.empty()) {
        cout << -1 << nl;
        return;
    }
    
    if (two.size() >= 2) {
        int x = two.front();
        int y = two.back();
        cout << x << " " << x << " " << y << " " << y << nl;
        return;
    }
    
    int x = two.front();
    while (!st.empty()) {
        int y = *st.begin();
        st.erase(st.begin());
        
        auto it = st.lower_bound(y + 2 * x);
        if (it == st.begin()) continue;
        --it;
        int z = *it;
        cout << x << " " << x << " " << y << " " << z << nl;
        return;
    }
    
    cout << -1 << nl;
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