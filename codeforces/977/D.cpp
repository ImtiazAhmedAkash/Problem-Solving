/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Divide by three, multiply by two

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
    vector<array<ll, 3>> A(n);
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        ll tmp = x;
        
        int three = 0;
        while (tmp % 3 == 0) {
            three++;
            tmp /= 3;
        }
        
        int two = 0;
        while (tmp % 2 == 0) {
            two++;
            tmp /= 2;
        }
        
        A[i] = {-three, two, x};
    }
    
    sort(A.begin(), A.end());
    
    for (auto &[a, b, ans] : A) {
        cout << ans << " ";
    }
    cout << nl;
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