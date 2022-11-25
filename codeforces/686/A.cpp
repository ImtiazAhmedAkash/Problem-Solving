// Free Ice Cream

#include <bits/stdc++.h>
using namespace std;

/*
 * If the sign is '+', the amount will be added to the stock.
 * otherwise, the sign is '-'
 * If the sign is '-', and there is enough to fulfill the demand,
 * the amount will be deducted from the stock.
 * else, the kid will be depressed. Count the depressed kid.
 * Finally, print the final stock and total count of depressed kid.
 */

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int test, stock;
    cin >> test >> stock;

    char sign;
    int amount, cry = 0;
    while (test--)
    {
        cin >> sign >> amount;

        if (sign == '+')
            stock += amount;
        else

        {
            if (stock >= amount)
                stock -= amount;
            else
                cry++;
        }
    }

    cout << stock << ' ' << cry << '\n';

    return 0;
}