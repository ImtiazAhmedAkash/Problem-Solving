/*  In the Name of ALLAH, the most gracious, the most merciful  */

// String Game

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
    string s, t;
    cin >> s >> t;
    int n = s.size();
    vector<int> A(n);
    for (auto &x : A) cin >> x;
    
    auto check = [&] (int mid) {
        string tmp = s;
        for (int i = 0; i < mid; i++) {
            tmp[A[i] - 1] = '.';
        }
        string cur  = "";
        for (int i = 0; i < n; i++) {
            if (tmp[i] != '.') cur += tmp[i];
        }
        int indx = 0;
        for (int i = 0; i < cur.size(); i++) {
            if (cur[i] == t[indx]) {
                indx++;
                if (indx == t.size()) return true;
            }
        }
        return false;
    };
    
    int L = -1, R = n;
    while (L < R) {
        int M = L + (R - L + 1) / 2;
        if (check(M)) L = M;
        else R = M - 1;
    }
    cout << R << nl;
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