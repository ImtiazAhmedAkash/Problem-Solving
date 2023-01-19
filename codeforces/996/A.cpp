/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Hit the Lottery

#include <bits/stdc++.h>
using namespace std;

/*
 * Create an array in decreasing order with all the bills available.
 * Divide the n by all the elements of the array and then store the remainder in n.
 * Finally, the value of res is the required output.
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int arr[] = {100, 20, 10, 5, 1}, n;
    cin >> n;

    int res = 0;
    for (int i = 0; i < 5; i++) {
        res += n / arr[i];
        n %= arr[i];
    }

    cout << res << '\n';

    return 0;
}