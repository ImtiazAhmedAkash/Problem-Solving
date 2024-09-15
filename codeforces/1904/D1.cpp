/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Set To Max (Easy Version)

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
    for (auto &x : A) cin >> x;
    vector<int> B(n);
    for (auto &x : B) cin >> x;

    vector<pair<int, int>> C(n);
    for (int i = 0; i < n; i++) {
        C[i] = {B[i], i};
    }
    sort(C.begin(), C.end());

    for (int indx = 0; indx < n; indx++) {
        int i = C[indx].second;
        if (A[i] == B[i]) continue;
        if (A[i] > B[i]) break;

        bool left = false;
        for (int j = i - 1; j >= 0; j--) {
            if (A[j] > B[i] || B[j] < B[i]) break;
            if (A[j] == B[i]) {
                for (int k = j; k <= i; k++) {
                    A[k] = B[i];
                }
                left = true;
            }
        }

        if (not left) {
            for (int j = i + 1; j < n; j++) {
                if (A[j] > B[i] || B[j] < B[i]) break;
                if (A[j] == B[i]) {
                    for (int k = i; k <= j; k++) {
                        A[k] = B[i];
                    }
                }
            }
        }
    }

    cout << (A == B ? "Yes" : "No") << nl;
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