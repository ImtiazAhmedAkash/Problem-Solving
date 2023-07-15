/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Find by Query

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define mod 998244353
#define N 2005
#define deb(x) cerr << #x << " = " << x << nl

void solve() {
    int n;
    cin >> n;
    int l = 1, r = n;
    while (r > l + 1) {
        int mid = (l + r) / 2;
        cout << "? " << mid << endl;
        int x;
        cin >> x;
        if (x == 0) l = mid;
        else r = mid;
    }
    cout << "! " << l << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    solve();
    
    return 0;
}