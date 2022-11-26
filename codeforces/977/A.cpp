// Wrong Subtraction

#include <bits/stdc++.h>
using namespace std;

/*
 * If the last digit of the number is 0, remove the last digit
 * by dividing the number by 10.
 * Otherwise, decrease the number by 1. 
 * Repeat this k times.
 */

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    while (k--)
    {
        if (n % 10 == 0)
            n /= 10;
        else
            n--;
    }

    cout << n << '\n';

    return 0;
}