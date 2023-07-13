/*  In the Name of ALLAH, the most gracious, the most merciful  */

// String Delimiter

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

void solve() {
    int n;
    cin >> n;
    string str;
    cin >> str;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (str[i] == '"') cnt++;
        else if (str[i] == ',' && !(cnt & 1)) str[i] = '.';
    }
    cout << str << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}