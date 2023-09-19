/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Easy Assembly

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = (1 << 30);
const ll INF =(1LL << 62);
const int mod = 998244353;
const int N = 2e5 + 5;

void solve() {
    int block;
    cin >> block;
    vector<int> a;
    vector<int> c[block];
    for (int i = 0; i < block; i++) {
        int n;
        cin >> n;
        while (n--) {
            int x;
            cin >> x;
            a.push_back(x);
            c[i].push_back(x);
        }
    }
    sort(a.begin(), a.end());
    int split = 0;
    for (int i = 0; i < block; i++) {
        vector<int> indx;
        for (auto x : c[i]) {
            indx.push_back(lower_bound(a.begin(), a.end(), x) - a.begin());
        }
        for (int j = 0; j + 1 < indx.size(); j++) {
            if (indx[j + 1] - indx[j] != 1) split++;
        }
    }
    cout << split << " " << block + split - 1 << nl;
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