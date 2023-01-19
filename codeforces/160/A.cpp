/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Twins

#include <bits/stdc++.h>
using namespace std;

/*
 * The boy wants to have coins, the sum of which is greater than the rest (in minimum steps).
 * First of all, sort the array in descending order.
 * Then, take a variable, curr(current) = 0.
 * While (curr <= sum), add the first value in curr, and subtract it from sum. Then check again.
 * The value of i when curr > sum, is the answer.
 */

// comparator function to sort in descending order
// this can also be done using sort(arr, arr + n, greater<int>());
bool descending(int a, int b) {
    return a > b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int arr[n], sum = 0;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    sort(arr, arr + n, descending);

    int curr = 0, i = 0;

    while (curr <= sum) {
        curr += arr[i];
        sum -= arr[i];
        i++;
    }

    cout << i << '\n';

    return 0;
}