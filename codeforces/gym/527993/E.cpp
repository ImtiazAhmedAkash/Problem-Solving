/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Jor Shongkot

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
    for (auto& x : A) cin >> x;
    
    for (int bit = 0; bit <= 20; bit++) {
        int c = 1 << bit;
        int d = 1 << (bit + 1);
        int need = ((n + 1) / d) * c + max(0, (n + 1) % d - c);
        if (bit > __lg(n)) need = 0;
        
        int one = 0, zero = 0;
        for (int i = 0; i < n; i++) {
            if ((A[i] >> bit) & 1) one++;
            else zero++;
        }
        
        if (zero == need) {
            for (int i = 0; i < n; i++) {
                A[i] ^= (1 << bit);
            }
        }
    }
    
    sort(A.begin(), A.end());
    for (int i = 1; i <= n; i++) {
        if (A[i - 1] != i) {
            cout << "NO" << nl;
            return;
        }
    }
    cout << "YES" << nl;
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