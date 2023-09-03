/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Prefix Sum Primes

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define N 300005
#define deb(x) cerr << #x << " = " << x << nl
const ll mod = 998244353;

void solve() {
    int n;
    cin >> n;
    int one = 0, two = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x == 1) one++;
        else two++;
    }
    if (two) {
        cout << 2 << " ";
        two--;
    }
    if (one) {
        cout << 1 << " ";
        one--;
    }
    for (int i = 0; i < two; i++) cout << 2 << " ";
    for (int i = 0; i < one; i++) cout << 1 << " ";
    cout << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}