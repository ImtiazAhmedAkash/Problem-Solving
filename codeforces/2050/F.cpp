/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Maximum modulo equality

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;

template <typename T>
struct SparseTable {
    vector<vector<T>> table;

    void build(const vector<T>& V) {
        int n = V.size();
        table.assign(n + 1, vector<T>(18));
        for (int i = 1; i <= n; i++) {
            table[i][0] = V[i];
        }
        for (int j = 1; (1 << j) <= n; j++) {
            for (int i = 1; i + (1 << j) - 1 <= n; i++) {
                table[i][j] = gcd(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    T query(int l, int r) const {
        int k = __lg(r - l + 1);
        return gcd(table[l][k], table[r - (1 << k) + 1][k]);
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> A(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    vector<int> diff(n + 1);
    for (int i = 2; i <= n; i++) {
        diff[i] = abs(A[i] - A[i - 1]);
    }
    
    SparseTable<int> st;
    st.build(diff);
    
    while (q--) {
        int l, r;
        cin >> l >> r;
        if (l == r) {
            cout << 0 << " ";
            continue;
        }
        
        cout << st.query(l + 1, r) << " ";
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