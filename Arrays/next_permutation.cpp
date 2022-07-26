/* 
Next_permutation : Find next lexicographically greater permutation
Input format: Arr[] = {1,3,2}

Output: Arr[] = {2,1,3}

Explanation: All permutations of {1,2,3} are {{1,2,3} , {1,3,2}, {2,13} , {2,3,1} , {3,1,2} , {3,2,1}}. So, 
the next permutation just after {1,3,2} is {2,1,3}.
*/
// Solution1: Brute Force: Finding all possible permutations
/*
Approach:
	a. Find all possible permutations of elements present and store them.
	b. Search input from all possible permutations.
	c. Print the next permutation present right after it.
Time Complexity: O(N!xN) where N is the no of elements
*/

// Solution2: Using C++ in-build function
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int arr[] = {1, 3, 2};
	next_permutation(arr, arr+3); // using in-built function of C++
	cout << arr[0] << " " << arr[1] << " " << arr[2];
	return 0;
}

// Solution3
/*
Approach:
	a.	Linearly traverse array from backward such that ith index value of the array
	is less than (i+1)th index value. Store that index in a variable.
	b. If the index value received from step 1 is less than 0. This means the given input
	array is the largest lexicographical permutation. Hence, we will reverse the input array
	to get the minimum or starting permutation. Linerarly traverse array from backward. Find
	an index that has a value greater than the previously found index. Store index is another
	variable.
	c. Swap values present in indices found in the above two steps.
	d. Reverse array from index+1 where the index is found at step 1 till end of the array.
*/

class Solution {
public:
	void next_permutation(vector<int> &nums) {
		int n = nums.size(), k, l;
		for (k = n-2; k >= 0; k--) {
			if (nums[k] < nums[k+1]) {
				break;
			}
		}

		if (k < 0) {
			reverse(nums.begin(), nums.end());
		} else {
			for (l = n-1; l > k; l--) {
				if (nums[l] > nums[k]) {
					break;
				}
			}
			swap(nums[k], nums[l]);
			reverse(nums.begin()+k+1, nums.end());
		}
	}
};

// Time complexity: O(N)
