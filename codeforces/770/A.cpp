// New Password

#include <bits/stdc++.h>
using namespace std;

/*
 * n is the total number of letter to be printed,
 * k is the total number of distinct letters
 * and two consecutive letters have to be distinct.
 *
 * First of all, print k-consecutive letter from the letter 'a'.
 * It fulfills the distinct conditions part.
 * Update the value of n by subtracting k from it.
 * Then print the remaining letters from 'a' to min(k, n) as long as n > 0.
 * After some time, n may be less than k.
 * In that case, the loop must stop after iterating n times.
 * That's why, the condition is 'a' + min(k, n).
 */

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    while (n > 0)
    {
        for (char i = 'a'; i < 'a' + min(k, n); i++)
            cout << i;

        n -= k;
    }

    return 0;
}