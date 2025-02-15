/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// D - Stone XOR

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
    vector<ll> A(n);
    for (auto &x : A) cin >> x;
    
    unordered_set<ll> ans;
    auto dfs = [&](auto&& self, int indx, vector<ll> v) -> void {
        if (indx == n) {
            ll Xor = 0;
            for (auto &x : v) {
                Xor ^= x;
            }
            ans.insert(Xor);
            return;
        }
        
        if (indx == 0) self(self, indx + 1, {A[indx]});
        else {
            for (int i = 0; i < v.size(); i++) {
                v[i] += A[indx];
                self(self, indx + 1, v);
                v[i] -= A[indx];
            }
            v.push_back(A[indx]);
            self(self, indx + 1, v);
        }
    };
    
    dfs(dfs, 0, vector<ll>());
    cout << ans.size() << nl;
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