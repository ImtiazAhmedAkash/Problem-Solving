/*  In the Name of ALLAH, the most gracious, the most merciful  */

// N Choice Question

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define INF (1 << 30)
#define mod 998244353
#define N 300005
#define deb(x) cerr << #x << " = " << x << nl

/*
 * The task is to find out the position of the number that equals (a + b).
 * 
 * Iterate a loop from 1 to n, and take inputs.
 * When the input is equal to (a + b), store the position of the loop iteration.
 * The stored position is the answer.
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, a, b;
    cin >> n >> a >> b;

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (x == a + b) ans = i;
    }

    cout << ans << nl;

    return 0;
}