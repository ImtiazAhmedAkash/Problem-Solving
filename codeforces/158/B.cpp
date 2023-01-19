/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Taxi

#include <bits/stdc++.h>
using namespace std;

/*
 * The array arr stores the element count of its respective indexes (from 1 to 4).
 * A group of 4 friends will go in the same taxi. So, for n group of 4 freinds, minimum n taxi is needed.
 *
 * 2 group of 2 friends can go in the same taxi. So, for n group of 2 friends, minimum n/2 taxi is needed.
 * If the n here is an odd number, then 1 group of 2 friends are left. (rem_two)
 *
 * 1 group of 3 friends and 1 group of 1 friend can go in the same taxi.
 * Now if,  x (the number of group of 3 friends) >= y (the number of 1 friends), they will need minimum x taxi.
 * Plus for the remaining group of 2 friends, 1 more taxi will be needed.
 *
 * Otherwise, we will need (x + (y - x) + rem_two * 2 + 3) / 4 taxis.
 * Here, by rem_two * 2, we have converted them into total number of friends.
 * And + 3 was added before dividing by 4 for handling some cases.
 * Like, if there are 5, 6, 7 or 8 friends, we need 2 taxis. So, we added the biggest mod possible for 4,
 * To calculate the total number of taxis.
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    int arr[5] = {0}, val;

    while (t--) {
        cin >> val;
        arr[val]++;
    }

    int add;

    int rem_two = arr[2] % 2;

    if (arr[3] >= arr[1])
        add = arr[3] + rem_two;
    else
        add = arr[3] + (arr[1] - arr[3] + (rem_two * 2) + 3) / 4;

    cout << arr[4] + (arr[2]) / 2 + add << '\n';

    return 0;
}