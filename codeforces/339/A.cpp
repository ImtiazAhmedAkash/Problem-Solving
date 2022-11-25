// Helpful Maths

#include <bits/stdc++.h>
using namespace std;

/*
 * Apply a bubble sort between the digits in ascending order.
 * The digits are located at index 0, 2, 4,...s.size() - 1.
 * As there are '+' signs in between two digits,
 * the value is incremented by 2.
 * Finally, print the string.
 */

int main()
{
	string s;
	cin >> s;
	int length = s.size();

	for (int i = 0; i < length; i += 2)
	{
		for (int j = i + 2; j < length; j += 2)
		{
			if (s[i] > s[j])
				swap(s[i], s[j]);
		}
	}

	cout << s;

	return 0;
}