// Juicer

#include <bits/stdc++.h>
using namespace std;

/*
 * If the orange size is less than or equal to the limit,
 * only then it will be put into the juicer.
 * Sum up the total oranges size that goes in the juicer.
 * If sum is greater than the wastelimit, clear the waste
 * i.e. assign 0 to the sum. And count
 */

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int num, sizeLimit, wasteLimit;
    cin >> num >> sizeLimit >> wasteLimit;

    int value, sum = 0, count = 0;

    while (num--)
    {
        cin >> value;

        if (value <= sizeLimit)
        {
            sum += value;

            if (sum > wasteLimit)
            {
                count++;
                sum = 0;
            }
        }
    }

    cout << count << "\n";

    return 0;
}