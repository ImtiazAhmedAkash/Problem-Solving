// Die Roll

#include <bits/stdc++.h>
using namespace std;

#define max(a, b) ((a > b) ? a : b)

/*
 * If Dot can get the maximum amount of Yakko or Okko, he will win.
 * So the total possible events of winning is (6 + 1) - max(Yakko, Okko).
 * 1 is added because the maximum value is also a possible event of winning.
 * 
 * The output must be printed in a fraction.
 * Thats why, divide the total possible events and total events by their gcd.
 */

int gcd(int a, int b)
{
    return (b == 0) ? a : gcd(b, a % b);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int a, b;
    cin >> a >> b;

    a = 7 - max(a, b);
    int g = gcd(6, a);

    cout << a / g << "/" << 6 / g;

    return 0;
}