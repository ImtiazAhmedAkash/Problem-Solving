/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Make a Rectangle

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
    map<int, int> M;
    vector<int> A = {0, 0};
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        M[x]++;
        if (M[x] == 2) {
            A.push_back(x);
            M[x] = 0;
        }
    }
    sort(A.begin(), A.end(), greater());
    cout << 1LL * A[0] * A[1] << nl;
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