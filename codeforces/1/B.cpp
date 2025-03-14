/*  In the Name of ALLAH, the most gracious, the most merciful  */

/*  And whoever puts their trust in ALLAH, He alone is sufficient for them. Al-Quran (65:3)  */

// B - Spreadsheets

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "Dbug.h"
#else
#define dbg(...)
#endif

using ll = long long;
constexpr char nl = '\n';

const int inf = 1e9;
const ll INF = 1e18;
const int mod = 998244353;
const int N = 2e5 + 5;

void solve() {
    string s;
    cin >> s;

    int n = s.size();
    int type = 1;
    int first_digit = -1;
    int first_char = -1;
    for (int i = 0; i < n; i++) {
        if (isdigit(s[i])) {
            first_digit = i;
            break;
        }
    }

    for (int i = first_digit; i < n; i++) {
        if (isalpha(s[i])) {
            first_char = i;
            type = 2;
            break;
        }
    }

    if (type == 1) {  // BC23
        string c = s.substr(0, first_digit);
        string r = s.substr(first_digit);

        int col = 0;
        int mul = 1;
        for (int i = c.size() - 1; i >= 0; i--) {
            col += mul * (c[i] - 'A' + 1);
            mul *= 26;
        }
        c = to_string(col);
        cout << "R" << r << "C" << c << nl;
    } else {  // R23C55
        string r = s.substr(1, first_char - 1);
        string c = s.substr(first_char + 1);

        int col = stoi(c);
        col--;
        c.clear();
        while (col / 26) {
            c += (char)('A' + (col % 26));
            col /= 26;
            col--;
        }
        c += (char)('A' + (col % 26));
        reverse(c.begin(), c.end());

        cout << c << r << nl;
    }
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