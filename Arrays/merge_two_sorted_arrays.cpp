/*
Merge two sorted arrays without Extra space
Problem statement:
	Given two sorted arrays arr1[] and arr2[] of sizes n and m in
non-decreasing order. Merge them in sorted order. Modify arr1 so that
it contains the first N elements and modify arr2 so that it contains
the last M elements.
Example 1:

Input: 
n = 4, arr1[] = [1 4 8 10] 
m = 5, arr2[] = [2 3 9]

Output: 
arr1[] = [1 2 3 4]
arr2[] = [8 9 10]

Explanation:
After merging the two non-decreasing arrays, we get, 1,2,3,4,8,9,10.

Example2:

Input: 
n = 4, arr1[] = [1 3 5 7] 
m = 5, arr2[] = [0 2 6 8 9]

Output: 
arr1[] = [0 1 2 3]
arr2[] = [5 6 7 8 9]

Explanation:
After merging the two non-decreasing arrays, we get, 0 1 2 3 5 6 7 8 9.
*/
// Solution1: Brute Force
/*
Approach:
	a.	Make an arr3 of size m+n.
	b.	Put elements arr1 and arr2 in arr3.
	c.	Sort the arr3.
	d.	Now first fill the arr1 and then fill remaining elements in arr2.
*/

#include <iostream>
using namespace std;

void merge(int arr1[], int arr2[], int n, int m) {
	int arr3[n+m];
	int k = 0;
	for (int i = 0; i < n; i++) {
		arr3[k++] = arr1[i];
	}

	for (int j = 0; j < m; j++) {
		arr3[k++] = arr2[j];
	}

	sort(arr3, arr3+m+n);

	k = 0;
	for (int i = 0; i < n; i++) {
		arr1[i] = arr3[k++];
	}
	for(int j = 0; j < m; j++) {
		arr2[j] = arr3[k++];
	}
}
// Time complexity: O(NlogN)+O(N)+O(N)
// Space complexity: O(N)
int main() {
    int arr1[] = {1,4,7,8,10};
	int arr2[] = {2,3,9};
    cout<<"Before merge:"<<endl;
    for (int i = 0; i < 5; i++) {
      cout<<arr1[i]<<" ";
    }
    cout<<endl;
    for (int i = 0; i < 3; i++) {
      cout<<arr2[i]<<" ";
    }
    cout<<endl;
    merge(arr1, arr2, 5, 3);
    cout<<"After merge:"<<endl;
    for (int i = 0; i <5; i++) {
      cout<<arr1[i]<<" ";
    }
    cout<<endl;
    for (int i = 0; i < 3; i++) {
      cout<<arr2[i]<<" ";
    }
    return 0;
}

// Solution2: Without using space
/*
Approach:
	a.	Use a for loop in arr1
	b. Whenever we get any element in arr1 which is greater than the first
	element of arr2, swap it.
	c.	Rearrange arr2.
	d. Repeat the process.
*/

void merge(int arr1[], int arr2[], int n, int m) {
	int i, k;
	for (int i = 0; i < n; i++) {
		// take first element from arr1
		// compare it with first element of second array
		// if condition match then swap
		if (arr1[i] > arr2[0]) {
			int tmp = arr1[i];
			arr1[i] = arr2[0];
			arr2[0] = tmp;
		}

		// then sort the second array
		// put the element in its correct position
		// so that next cycle can swap elements correctly
		int first = arr2[0];
		// insertion sort used here
		for (k = 1; k < m && arr2[k] < first; k++) {
			arr2[k-1] = arr2[k];
		}
		arr2[k-1] = first;
	}
}
// Time complexity: O(m*n)
// Space complexity: O(1)

// Solution3: Gap method
/*
Approach:
	a.	Initially take gap as (M+N)/2
	b.	Take a pointer1 = 0 and pointer2 = gap
	c.	Run a loop from pointer1 & pointer to m+n and whenever arr[pointer2] < arr[pointer1]
	just swap those
	d.	After completion of the loop reduce the gap as gap = gap/2
	e.	Repeat the process until gap > 0
*/
#include <math.h>
void merge(int arr1[], int arr2[], int n, int m) {
	int gap = ceil((float)(n+m) / 2);
	while (gap > 0) {
		int i = 0;
		int j = gap;
		while (j < (n+m)) {
			if (j < n && arr1[i] > arr1[j]) {
				swap(arr1[i], arr1[j]);
			} else if(j >= n && i < n && arr1[i] > arr2[j-n]) {
				swap(arr1[i], arr2[j-n]);
			} else if (j >= n && i >= n && arr2[i-n] > arr2[j-n]) {
				swap(arr2[j-n], arr2[i-n]);
			}
			i++;
			j++;
		}
		if (gap == 1) {
			gap = 0;
		} else {
			gap = ceil((float) gap/2);
		}
	}
}

// Time complexity: O(logN)
// Space complexity: O(1)
