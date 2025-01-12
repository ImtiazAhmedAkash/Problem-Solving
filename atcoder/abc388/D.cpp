/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Coming of Age Celebration

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
    vector<ll> A(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    
    map<ll, int> ends;
    int bankrupt = 0;
    for (int i = 1; i <= n; i++) {
        A[i] += (i - 1 - bankrupt);
        
        ll donate = min(A[i], (ll) n - i);
        A[i] -= donate;
        ends[i + donate]++;
        
        bankrupt += ends[i];
    }
    
    for (int i = 1; i <= n; i++) {
        cout << A[i] << " \n"[i == n];
    }
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