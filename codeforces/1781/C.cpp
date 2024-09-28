/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Equal Frequencies

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
    string s;
    cin >> s;

    vector A(26, vector<int>());
    for (int i = 0; i < n; i++) {
        int indx = s[i] - 'a';
        A[indx].push_back(i);
    }

    vector<int> order(26);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int i, int j) {
        return A[i].size() > A[j].size();
    });

    int best = 0;
    string ans = "";

    for (int i = 1; i <= 26; i++) {
        if (n % i) continue;

        int cur = 0;
        int freq = n / i;
        for (int j = 0; j < i; j++) {
            cur += min((int)A[order[j]].size(), freq);
        }

        if (best < cur) {
            best = cur;
            ans = string(n, '.');
            vector<char> extra;
            for (int j = 0; j < i; j++) {
                int indx = order[j];
                int x = min((int)A[indx].size(), freq);
                for (int k = 0; k < x; k++) {
                    ans[A[indx][k]] = indx + 'a';
                }
                for (int k = x; k < freq; k++) {
                    extra.push_back(indx + 'a');
                }
            }
            for (int j = 0; j < n; j++) {
                if (ans[j] == '.') {
                    ans[j] = extra.back();
                    extra.pop_back();
                }
            }
        }
    }

    cout << n - best << nl;
    cout << ans << nl;
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