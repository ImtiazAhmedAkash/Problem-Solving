// Buy a Shovel

#include <bits/stdc++.h>
using namespace std;

/*
 * If the remainder of total price (k * i) by 10
 * is equal to 0 or r, i is the minimum number of shovel 
 * needed to be bought.
 */

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int k, r;
    cin >> k >> r;

    for (int i = 1; i <= 10; i++)
    {
        if ((k * i) % 10 == r || (k * i) % 10 == 0)
        {
            cout << i;
            break;
        }
    }
    return 0;
}