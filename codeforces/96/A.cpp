/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Football

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

/*
 * Find out how many adjacent elements are the same.
 * If the count is greater than or equal 7, the answer is "YES".
 * Otherwise, the answer is "NO".
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string str, ans = "NO";
    cin >> str;
    int cnt = 1;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] != str[i + 1] || i == str.size() - 1) {
            if (cnt >= 7) ans = "YES";
            cnt = 1;
            continue;
        }
        cnt++;
    }
    cout << ans << nl;

    return 0;
}