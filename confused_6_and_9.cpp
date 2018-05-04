/*
https://practice.geeksforgeeks.org/problems/confused-pappu/0/?ref=self
Pappu is confused between 6 & 9 . He works in billing department of abc company and his work is to return the remaining amount to the costumers.

if actual remaining amount is given we need to find the maximum possible extra amount given by the pappu to the costumers.

For ex:-

actual remaining amount = 56

so , maximum possible extra amount = 3  (59 - 56 )

Input

The first line of the input contains a single integer T denoting the number of test cases.
The first line of each test case contains N (actual remaining amount).

Output

For each test case, output the maximum possible extra amount in newline.

Constraints
    •    1 ≤ T ≤ 102

    •    1 ≤ N≤ 10000001

Example

Input:

3

6

66

666

Output:

3

33

333
*/

#include <iostream>
#include <string>
using namespace std;

string replace_6(string n) {
	for (string :: iterator it = n.begin(); it < n.end(); it++) {
		if (*it == '6')
			*it = '9';
	}
	return n;
}




int main() {
	int T = 0;
	cin >> T;
	while (T > 0) {
		string n = "";
		while (n.length() == 0)
		    cin >> n;
		    cout << stoi(replace_6(n)) - stoi(n) <<endl;
		    T--;
	}

	return 0;
}