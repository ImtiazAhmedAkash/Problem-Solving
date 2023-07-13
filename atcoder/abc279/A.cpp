/*  In the Name of ALLAH, the most gracious, the most merciful  */

// wwwvvvvvv

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

void solve() {
    string str;
    cin >> str;
    int a = count(str.begin(), str.end(), 'w');
    cout << ((int)str.size() + a) << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}