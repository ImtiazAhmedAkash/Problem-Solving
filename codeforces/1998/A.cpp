/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Find K Distinct Points with Fixed Center

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
    int x, y, k;
    cin >> x >> y >> k;

    vector<int> X;
    int sum = 0;
    for (int i = 1; i < k; i++) {
        int z = i;
        if (x > 0) z *= -1;
        X.push_back(z);
        sum += z;
    }
    X.push_back(k * x - sum);

    vector<int> Y;
    sum = 0;
    for (int i = 1; i < k; i++) {
        int z = i;
        if (y > 0) z *= -1;
        Y.push_back(z);
        sum += z;
    }
    Y.push_back(k * y - sum);

    for (int i = 0; i < k; i++) {
        cout << X[i] << " " << Y[i] << nl;
    }
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