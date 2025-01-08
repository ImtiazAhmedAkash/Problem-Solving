/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Move Segment

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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    
    vector<pair<char, int>> A;
    for (int i = 0; i < n; i++) {
        int j = i;
        int cnt = 0;
        while (j < n && s[i] == s[j]) {
            cnt++, j++;
        }
        A.push_back({s[i], cnt});
        i = j - 1;
    }
    
    int indx = 0;
    if (A.front().first == '0') {
        indx = 2 * k - 1;
    } else {
        indx = 2 * k - 2;
    }
    
    swap(A[indx], A[indx - 1]);
    
    string ans;
    for (auto &[a, b] : A) {
        ans += string(b, a);
    }
    
    cout << ans << nl;
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