/*  In the Name of ALLAH, the most gracious, the most merciful  */

// Fence

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

/*
 * Take an arr[n + 1], in order to start from index 1 instead of 0.
 * While taking the input, calculate the sum of the input elements.
 * The checking will not start until the sum till k-th index is calculated.
 * Once k-th index is reached, if (sum < best), assign sum to best.
 * and resultant index will be, res = i + 1 - k.
 * res represents the starting index of i, from which the sum of k consecutive element is the minimum.
 *
 * From the k-th index, keep subtracting the (i + 1 - k)-th value from the sum.
 * This means, adding an element from the end, and subtracting an element from the front.
 * The value of res after the loop is terminated, is the answer.
 *
 * The given test case:
 * 7 3
 * 1 2 6 1 1 7 1
 *
 * Here, calculate sum of first 3 elements first. Which is 9. Now, i = 3.
 * As (sum (9) < best), best = sum (9) and res = (3 - 3 + 1) = 1.
 * Then, subtract the first value from sum. So, sum becomes 8.
 *
 * -> Similarly, sum = 9. when i = 4. (this sum is for element 2nd to 4th).
 * Sum = 9 - arr[2] (arr[4 - 3 + 1]) = 7.
 *
 * -> sum = 8 when i = 5. (sum is form element 3rd to 5th).
 * best (9) > sum (8), so best = sum and res = (5 - 3 + 1) = 3
 * Sum = 2;
 *
 * -> sum = 9 when i = 6.
 * sum = 8;
 *
 * -> sum = 9, when i = 7.
 * sum = 8;
 */

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    int arr[n + 1], res;
    ll best = LLONG_MAX, sum = 0;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        sum += arr[i];

        if (i >= k) {
            if (sum < best) {
                best = sum;
                res = i + 1 - k;
            }
            sum -= arr[i + 1 - k];
        }
    }

    cout << res << '\n';

    return 0;
}