/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Numeric String Template

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

    int q;
    cin >> q;
    while (q--) {
        string s;
        cin >> s;
        if (s.size() != n) {
            cout << "NO" << nl;
            continue;
        }

        map<int, char> Num;
        map<char, int> Char;
        bool ok = true;
        for (int i = 0; i < n; i++) {
            if ((Char.count(s[i]) && Char[s[i]] != A[i]) || (Num.count(A[i]) && Num[A[i]] != s[i])) {
                ok = false;
                break;
            }
            Num[A[i]] = s[i];
            Char[s[i]] = A[i];
        }
        cout << (ok ? "YES" : "NO") << nl;
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