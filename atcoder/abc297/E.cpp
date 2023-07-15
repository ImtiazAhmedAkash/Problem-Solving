/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Kth Takoyaki Set

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define mod 998244353
#define N 300005
#define deb(x) cerr << #x << " = " << x << nl

void solve() {
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (auto &i : a) cin >> i;
    
    set<ll> st = {0};
    for (int i = 0; i < k; i++) {
        auto x = *(st.begin());
        st.erase(x);
        for (auto u : a) st.insert(x + u);
    }
    
    cout << *(st.begin()) << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
    
    return 0;
}