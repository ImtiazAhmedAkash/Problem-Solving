/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Two Sets

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cerr << #x << " = " << x << nl

/*
 * Calculate the sum of 1, 2, ... , n using the formula.
 * If the sum is odd, it cannot be divided into two sets of equal sums.
 * So, return "NO".
 *
 * If the sum is even, it can be divided into two set of equal sums.
 * To do that, take two vector.
 * Divide the sum in half and assign it in a variable (lets say val).
 *
 * Iterate a loop from n to 1 backwards.
 * If a number is less than or equal to val, store it in vector a and
 * update the value of val by val -= number.
 *
 * If a number is bigger than val, store it in vector b.
 *
 * Finally, print the vectors with their respective sizes.
 */

void print(vector<int> v)
{
    cout << v.size() << nl;
    for (auto i : v)
        cout << i << " ";
    cout << nl;
}

void solve()
{
    ll n;
    cin >> n;

    ll sum = n * (n + 1) / 2;

    if (sum & 1)
    {
        cout << "NO" << nl;
        return;
    }

    cout << "YES" << nl;

    ll val = sum / 2;
    vector<int> a, b;

    for (int i = n; i > 0; i--)
    {
        if (i <= val)
        {
            a.push_back(i);
            val -= i;
        }
        else
            b.push_back(i);
    }

    print(a);
    print(b);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();

    return 0;
}