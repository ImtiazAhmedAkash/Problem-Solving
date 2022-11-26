// Elephant

#include <bits/stdc++.h>
using namespace std;

/*
 * The elephant needs at least n / 5 steps to reach position n.
 * If n is not divisible by 5, he needs an extra step.
 */

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int steps = n / 5;
    if (n % 5 != 0)
        steps++;

    cout << steps << '\n';

    return 0;
}