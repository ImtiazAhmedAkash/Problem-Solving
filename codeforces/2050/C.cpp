/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Uninteresting Number

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
    string s;
    cin >> s;
    vector<int> cnt(10);
    int sum = 0;
    for (auto &c : s) {
        sum += c - '0';
        cnt[c - '0']++;
        sum %= 9;
    }
    
    if (sum == 0) {
        cout << "YES" << nl;
        return;
    }
    
    sum = 9 - sum;
    
    auto possible = [&](int sum) -> bool {
        int six = min(sum / 6, cnt[3]);
        sum -= six * 6;
        int two = min(sum / 2, cnt[2]);
        sum -= two * 2;
        
        return sum == 0;
    };
    
    int mx = cnt[2] * 2 + cnt[3] * 6;
    for (sum; sum <= mx; sum += 9) {
        if (possible(sum)) {
            cout << "YES" << nl;
            return;
        }
    }
    
    cout << "NO" << nl;
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