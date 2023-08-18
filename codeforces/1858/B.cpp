/*  In the Name of ALLAH, the most gracious, the most merciful  */

// The Walkway

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int INF = (1 << 30);
const int mod = 998244353;
const int N = 2e5 + 5;

void solve() {
    int n, m, d;
    cin >> n >> m >> d;
    vector<int> s, cookies;
    map<int, int> mp;
    s.push_back(1);
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        if (x == 1) mp[0] = 1;
        else s.push_back(x);
    }
    
    int total = 1;
    cookies.push_back(1);
    for (int i = 1; i < s.size(); i++) {
        total += max(0, (s[i] - s[i - 1] - 1) / d);
        total++;
        cookies.push_back(total);
    }
    total += max(0, (n - s.back()) / d);
    cookies.push_back(total);
    
    int cur = 0, l = 0;
    for (int i = 2; i < s.size(); i++) {
        cur = cookies[i - 2];
        cur += 1 + max(0, (s[i] - s[i - 2] - 1) / d);
        
        l = cookies[i] - cur;
        mp[l]++;
    }
    cur = cookies[cookies.size() - 3];
    cur += max(0, (n - s[s.size() - 2]) / d);
    l = cookies.back() - cur;
    mp[l]++;
    
    auto it = mp.rbegin();
    cout << total - (*it).first << " " << (*it).second << nl;
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}