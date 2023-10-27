/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Koala and Lights

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 1005;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> T(N);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        int cur = s[i] - '0';
        for (int j = 1; j < N; j++) {
            T[j] += cur;
            if (j == b) {
                cur = !cur;
                b += a;
            }
        }
    }
    cout << *max_element(T.begin(), T.end()) << nl;
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