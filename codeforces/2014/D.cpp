/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Robert Hood and Mrs Hood

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
    int n, d, k;
    cin >> n >> d >> k;
    vector A(n + 1, vector<int>());
    for (int i = 0; i < k; i++) {
        int l, r;
        cin >> l >> r;
        A[l].push_back(r);
    }

    int min_job = inf, max_job = 0;
    int mom = 0, bro = 0;

    multiset<int> ends;
    for (int l = 1, r = 1; r <= n; r++) {
        if (!A[r].empty()) {
            for (auto &x : A[r]) {
                ends.insert(x);
            }
        }

        if (r - l + 1 == d) {
            int cur = ends.size();
            if (min_job > cur) {
                min_job = cur;
                mom = l;
            }
            if (max_job < cur) {
                max_job = cur;
                bro = l;
            }

            while (!ends.empty() && *(ends.begin()) == l) {
                ends.erase(ends.begin());
            }
            l++;
        }
    }
    cout << bro << " " << mom << nl;
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