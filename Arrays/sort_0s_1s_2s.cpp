/*
Sort an Array of 0s, 1s and 2s
Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]

Input: nums = [2,0,1]
Output: [0,1,2]

Input: nums = [0]
Input: nums = [0]
*/
// Solution1: Sorting 
// Time Complexity: O(N*log(N))

// Solution2: Keeping count of values
/*
	Since in this case there are only 3 distinct values in the array. So
it's easy to maintain the count of all, Like count of 0, 1, and 2. This can be
followed by overwriting the array based on the frequency(count) of values.

Approach:
	a.	Take 3 variables to maintain the count of 0, 1, and 2.
	b.	Travel the array once and increment the corresponding counting varibales
	c.	In 2nd Traversal of the array, we will now over write the first 'a' indices
	in array with '0', the next 'b' with '1' and remaining 'c' with '2'.
Time Complexity: O(N) + O(N)
*/

// Solution3: 3-pointer approach
/*
	This problem is a variation of popular Dutch National Flag algorithm
Approach:
	a.	Initialize 3 pointer such that low and mid will point to 0th index 
	and high pointer will point to last index.
		int low = arr[0]
		int mid = arr[0]
		int high = arr[n-1]
	b.	Now there will 3 different operation/steps based on the value of arr[mid] and
	will be repeated until mid <= high
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	void sortColors(vector<int> &nums) {
		int low = 0;
		int high = nums.size() - 1;
		int mid = 0;

		while (mid <= high) {
			switch(nums[mid]) {
				// if the element is 0
				case 0:
					swap(nums[low++], nums[mid++]);
					break;
				// if the element is 1
				case 1:
					mid++;
					break;
				// if the element is 2
				case 2:
					swap(nums(mid), nums[high--]);
					break;
			}
		}
	}
};

// Time complexity: O(N)

void printArray(vector<int> &nums) {
	for (int i = 0; i < nums.size(); i++)
		cout << nums[i] << " ";
	cout << endl;
}

int main() {
	vector<int> arr{1, 2, 0, 1, 2, 0, 0, 2, 1};
	Solution sol;
	sol.sortColors(arr);
	printArray(arr);
	return 0;
}
