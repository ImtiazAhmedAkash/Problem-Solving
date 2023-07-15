/*  In the Name of ALLAH, the most gracious, the most merciful  */

// AtCoder Cards

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define mod 998244353
#define N 300005
#define deb(x) cerr << #x << " = " << x << nl

void solve() {
    string a, b;
    cin >> a >> b;
    
    map<char, int> ma, mb;
    for (auto i : a) ma[i]++;
    for (auto i : b) mb[i]++;
    
    string s = "atcoder";
    for (char i = 'a'; i <= 'z'; i++) {
        if (ma[i] != mb[i]) {
            if (s.find(i) == string::npos) {
                cout << "No" << nl;
                return;
            }
            if (ma[i] > mb[i]) mb['@'] -= (ma[i] - mb[i]);
            else ma['@'] -= (mb[i] - ma[i]);
        }
    }
    
    if (ma['@'] < 0 || mb['@'] < 0) cout << "No" << nl;
    else cout << "Yes" << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
    
    return 0;
}