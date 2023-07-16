/*  In the Name of ALLAH, the most gracious, the most merciful  */

// racecar

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define mod 998244353
#define N 300005
#define deb(x) cerr << #x << " = " << x << nl

void solve() {
    int n;
    cin >> n;
    vector<string> a;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        a.push_back(s);
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            string s = a[i] + a[j];
            string t = s;
            reverse(t.begin(), t.end());
            if (s == t) {
                cout << "Yes" << nl;
                return;
            }
        }
    }
    
    cout << "No" << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
    
    return 0;
}