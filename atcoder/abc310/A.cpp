/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Order Something Else

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define mod 998244353
#define N 300005
#define deb(x) cerr << #x << " = " << x << nl

void solve() {
    int n, actual_price, discounted_price;
    cin >> n >> actual_price >> discounted_price;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    int y = *min_element(a.begin(), a.end());
    cout << min(actual_price, y + discounted_price) << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
    
    return 0;
}