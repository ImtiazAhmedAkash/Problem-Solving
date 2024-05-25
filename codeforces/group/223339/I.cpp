/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Count Vowels

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 1e5;

int isVowel(char ch) {
    ch = tolower(ch);
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') return 1;
    return 0;
}

int fun(string& str, int indx) {
    if (indx == str.size()) return 0;
    return isVowel(str[indx]) + fun(str, indx + 1);
}

void solve() {
    string s;
    getline(cin, s);
    cout << fun(s, 0);
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