/*  In the name of ALLAH, the most gracious, the most merciful  */

// Permutations

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cout << #x << " = " << x << nl

/*
 * For input 2 and 3, it is not possible to get such a permutation.
 * In other cases,
 * First, print the even numbers from 2 to n and
 * then print the odd numbers from 1 to n.
 */

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    if (n == 2 || n == 3)
    {
        cout << "NO SOLUTION" << nl;
        return 0;
    }

    for (int i = 2; i <= n; i += 2)
        cout << i << ' ';

    for (int i = 1; i <= n; i += 2)
        cout << i << ' ';

    cout << nl;

    return 0;
}