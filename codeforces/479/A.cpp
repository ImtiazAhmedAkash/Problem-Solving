/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Expression

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cout << #x << " = " << x << nl

/*
 * As there are only two operations available, there are only four combinations 
 * that can give the maximum value.
 * They are (a + b + c), (a * b * c), (a * (b + c)) and ((a + b) * c).
 * 
 * The maximum value of the four combinations is the answer.
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b, c;
    cin >> a >> b >> c;

    int res = max({a * b * c, a + b + c, (a + b) * c, a * (b + c)});

    cout << res << nl;

    return 0;
}