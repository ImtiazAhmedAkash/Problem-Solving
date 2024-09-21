/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  For today, you happen to be the defeated. But what will you become tomorrow?  */

// Password Cracking

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;

int ask(string s) {
    cout << "? " << s << endl;
    int x;
    cin >> x;
    return x;
}

void solve() {
    int n;
    cin >> n;
    
    string ans, tmp = "0";
    bool ok = true;
    bool done = false;
    while (ok && not done) {
        int x = ask(tmp);
        if (x) {
            ans = tmp;
            done = (ans.size() == n);
            tmp += '0';
        }
        else {
            tmp.back() = '1';
            x = ask(tmp);
            if (!x) {
                tmp.pop_back();
                ok = false;
            } else {
                ans = tmp;
                done = (ans.size() == n);
                tmp += '0';
            }
        }
    }
    
    tmp = '0' + tmp;
    while (not done) {
        int x = ask(tmp);
        if (!x) {
            tmp.front() = '1';
        }
        ans = tmp;
        done = (ans.size() == n);
        tmp = '0' + tmp;
    }
    
    cout << "! " << ans << endl;
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