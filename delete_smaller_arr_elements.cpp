/*
Given an array arr[] and a number k. The task is to delete k elements which are smaller than next element (i.e., we delete arr[i] if arr[i] < arr[i+1]) or become smaller than next because next element is deleted.

Input:
The first line contains an integer T, the number of test cases. For each test case, the first line contains an integer n, denoting the size of the array. Next line contains n space separated integers, followed by an integer k, denoting the number of elements to be deleted from the array.

Output:
For each test case, the output is the array arr[] after deleting the k elements from the array if possible, else print the left array as it is.

Constraints:
1<=T<=100
2<=n<=100
1<=k<=100

Example:
Input
4
3
3 100 1
1
5
20 10 25 30 40
2
5
23 45 11 77 18
3
2
2 5
2
Output
100 1
25 30 40
77 18
5

Explanation:
1. arr[0] < arr[1] means 3 is less than 100, so delete 3.
2. First we delete 10 because it follows arr[i] < arr[i+1]. Then we delete 20 because 25 is moved next to it and it also starts following the condition.
3. We delete 23, 45 and 11 as they follow the condition arr[i] < arr[i+1].
4.  As after deleting 2, we are left with 5 only and hence 5 is the answer.
*/

#include <iostream>
using namespace std;

void get_arr(int * arr, int n);
void delete_element(int * arr, int n, int i1);
void print_arr(int * arr, int n);
void delete_smaller(int * arr, int  n, int k);

void get_arr(int * arr, int n){
	for (int i = 0; i < n; i++){
		cin >> *(arr + i);
	}
}

void delete_element(int * arr, int n, int i1){
	for (int i = i1; i < (n-1); i++){
		*(arr + i) = *(arr + i + 1);
	} 
}

void print_arr(int * arr, int n){
	//cout << "Array = " ;
	for (int i = 0; i<n; i++){
		cout << *(arr+i) << " ";
	}
	cout << endl;
}

void delete_smaller(int * arr, int  n, int k){
	//print_arr(arr, n);
	int i = 0;
	while (i < (n-1)){
		if (*(arr+i) < *(arr+i+1) && k > 0){
			//cout << "Delete element " << i << ": " << *(arr + i) << endl;
			//print_arr(arr, n);
			delete_element(arr, n, i);
			n--;
			k--;
			//print_arr(arr, n);
			i = -1;
		}
		i++;
	}
	print_arr(arr, n);
}

int main() {
	int T = 0;
	cin >> T;
	while (T > 0) {
		int n = 0;
		cin >> n; 		// array size
		
		int * arr = new int[n];
		get_arr(arr, n);		// get array
		
		int k = 0;
		cin >> k;				// num of elements to delete
		
		delete_smaller(arr, n, k);
		delete[] arr;
		T--;
	}

	return 0;
}