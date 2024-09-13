/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Job Interview

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
    int n, m;
    cin >> n >> m;
    vector<int> A(n + m + 1);
    for (auto &x : A) cin >> x;
    vector<int> B(n + m + 1);
    for (auto &x : B) cin >> x;

    string s;
    int p = 0, t = 0;
    ll total = 0;
    for (int i = 0; i < n + m; i++) {
        if (t == m || (p < n && A[i] > B[i])) {
            s += 'p';
            p++;
            total += A[i];
        } else {
            s += 't';
            t++;
            total += B[i];
        }
    }

    vector<int> P, T;
    for (int i = 0; i < n + m; i++) {
        if (A[i] > B[i] && s[i] == 't') {
            P.push_back(i);
        } else if (A[i] < B[i] && s[i] == 'p') {
            T.push_back(i);
        }
    }

    vector<ll> ans(n + m + 1);
    ans.back() = total;
    for (int i = n + m - 1; i >= 0; i--) {
        if (s[i] == 'p') {
            auto it = upper_bound(P.begin(), P.end(), i);
            if (it == P.end()) {
                ans[i] = total - A[i] + A.back();
            } else {
                int indx = *it;
                ans[i] = total - A[i] + A[indx] - B[indx] + B.back();
            }
        } else {
            auto it = upper_bound(T.begin(), T.end(), i);
            if (it == T.end()) {
                ans[i] = total - B[i] + B.back();
            } else {
                int indx = *it;
                ans[i] = total - B[i] + B[indx] - A[indx] + A.back();
            }
        }
    }

    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << nl;
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