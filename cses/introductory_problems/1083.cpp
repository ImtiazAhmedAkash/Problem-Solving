/*  In the name of ALLAH, the most gracious, the most merciful  */

// Missing Number

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl '\n'
#define deb(x) cout << #x << " = " << x << nl

/*
 * First of all, calculate the sum of 1 to n number using the formula n * (n + 1) / 2.
 * After that, iterate a loop n - 1 times 
 * (not n times because 1 number is missing).
 * Every time take an input and subtract it from the sum.
 * The value of sum after all the input, is the answer.
 */

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;

    ll sum = n * (n + 1) / 2;
    ll val;

    for (int i = 1; i < n; i++)
    {
        cin >> val;
        sum -= val;
    }

    cout << sum << nl;

    return 0;
}