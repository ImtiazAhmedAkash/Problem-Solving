/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Removals Game

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
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    vector<int> B(n);
    for (int i = 0; i < n; i++) {
        cin >> B[i];
    }

    int l = 0, r = n - 1;
    bool ok = false;
    for (int i = 0; i < n; i++) {
        if (A[i] == B[l]) {
            l++;
        } else if (A[i] == B[r]) {
            r--;
        } else {
            ok = true;
            break;
        }
    }

    l = 0, r = n - 1;
    for (int i = n - 1; i >= 0; i--) {
        if (A[i] == B[l]) {
            l++;
        } else if (A[i] == B[r]) {
            r--;
        } else {
            ok = true;
            break;
        }
    }

    cout << (ok ? "Alice" : "Bob") << nl;
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