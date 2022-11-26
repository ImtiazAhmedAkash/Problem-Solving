// Soldier and Bananas
// Credit: https://codeforces.com/profile/ngfam_kongu

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
 * The value of the bananas are 1k, 2k, 3k...wk respectively. They form a series of natural number.
 * The formula for 1+2+3+...+n is n * (n + 1) / 2.
 * As k is common in all the number, the sum is multiplied by k
 * to find out the total expenses for buying k bananas.
 * If n is greater than total, he doesn't have to borrow any money.
 * Print the maximum of value between 0 and total - n.
 * To compare the maximum, both of the value should be of same data types.
 * That's why 0 is converted to long long using 0LL.
 */

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll k, n, w;
    cin >> k >> n >> w;

    ll total;
    total = w * (w + 1) * k / 2;

    cout << max(0LL, total - n) << '\n';

    return 0;
}