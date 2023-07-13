/*  In the Name of ALLAH, the most gracious, the most merciful  */

// LOOKUP

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

void solve() {
    string s1, s2;
    cin >> s1 >> s2;

    if (s1.find(s2) == string::npos)
        cout << "No";
    else
        cout << "Yes";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}