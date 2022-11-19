// Watermelon

#include <bits/stdc++.h>
using namespace std;

/*
 * If n is odd, it can never be divided into two even numbers.
 * In that case, one number will be odd, and the other will be even.
 *
 * Every even number can be divided into two even numbers except 2.
 * Thats why, if n is an even number and n is not 2, then print YES
 * Otherwise, print NO.
 */

int main()
{
    int n;
    cin >> n;

    if (n % 2 == 0 && n != 2)
        cout << "YES" << '\n';
    else
        cout << "NO" << '\n';

    return 0;
}