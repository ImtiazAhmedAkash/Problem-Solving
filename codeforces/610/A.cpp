// Pasha and Stick

#include <bits/stdc++.h>
using namespace std;

/*
 * If the input is an odd number, it is not possible to split the stick to satisfy the condition
 * In a rectangle, the opposite sides should be equal.
 * The addition of two such equal opposite sides are always even number.
 *
 * If the input is divisible by 4, then it is possible to split the stick in (n / 4) - 1 ways
 * For example, lets say, n = 8. The acceptable solution is {1, 1, 3, 3}.
 * {2, 2, 2, 2} is unacceptable as it forms a square. Thats the reason, 1 is subtracted.
 * Again, for n = 12, possible solutions are, {1, 1, 5, 5} and {2, 2, 4, 4}.
 * {3, 3, 3, 3} is unacceptable.
 *
 * otherwise, the input is an even number, but not divisible by 4.
 * Lets say, n = 6. The acceptable solution is {1, 1, 2, 2} i.e number of solutions = 1 = 6 / 4
 * Again, for n = 10, possible solutions are {1, 1, 4, 4}, {2, 2, 3, 3}. i.e. 2 = 10 / 4
 */

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    if (n % 2 != 0)
        cout << 0 << '\n';
    else if (n % 4 == 0)
        cout << (n / 4) - 1 << '\n';
    else
        cout << n / 4 << '\n';

    return 0;
}