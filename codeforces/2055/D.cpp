/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Scarecrow

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
    int n, k, l;
    cin >> n >> k >> l;
    k *= 2;
    l *= 2;
    vector<int> A(n);
    for (auto &x : A) {
        cin >> x;
        x *= 2;
    }
    
    ll ans = A.front();
    int cur = k;
    int indx = 0;
    while (cur < l && indx + 1 < n) {
        int next = A[indx + 1];
        int left = next - ans;
        int right = next + ans;
        if (left <= cur && cur <= right) {
            cur += k;
        } else if (right < cur && cur - right < k) {
            cur = right + k;
        } else if (cur < left) {
            int meet = (left + cur) / 2;
            ans += meet - cur;
            cur = meet + k;
        }
        indx++;
    }
    
    if (cur < l) {
        ans += l - cur;
    }
    
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