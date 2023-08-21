/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Chord

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define mod 998244353
#define N 300005
#define deb(x) cerr << #x << " = " << x << nl

void solve() {
    string s;
    cin >> s;
    set<string> st = {"ACE", "BDF", "CEG", "DFA", "EGB", "FAC", "GBD"};
    if (st.find(s) != st.end()) cout << "Yes" << nl;
    else cout << "No" << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    while (t--) {
        solve();
    }
    
    return 0;
}