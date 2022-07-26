/*
Kadane's Algorithm: Maximum Subarray Sum in an Array
Example 1:

Input: arr = [-2,1,-3,4,-1,2,1,-5,4] 

Output: 6 

Explanation: [4,-1,2,1] has the largest sum = 6. 

Examples 2: 

Input: arr = [1] 

Output: 1 

Explanation: Array has only one element and which is giving positive sum of 1. 
*/

// Solution1: Naive Solution
/*
Approach:
	Using three loops, we will get all possible subarrays in two loops and their
sum in another loop, and then return the maximum of them.
*/

#include <bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int> &nums, vector<int>& subArray) {
	int max_sum = INT_MIN;
	int n = nums.size();
	if (n == 1) {
		return num[0];
	}

	int i, j;
	for (i = 0; i <= n-1; i++) {
		for (j = i; j <= n-1; j++) {
			int sum = 0;
			for (k = i; k <= j; k++) {
				sum += nums[k];
			}
			if (sum > max_sum) {
				subArray.clear();
				max_sum = sum;
				subArray.push_back(i);
				subArray.push_back(j);
			}
		}
	}
	return max_sum;
}

int main() {
	vector<int> arr{-2, 1, -3, 4, -1, 2, 1, -5, 4};
	vector<int> subarray;
	int max_sum = maxSubArray(arr, subarray);
	cout << "The longest subarray with maximum sum: " << max_sum;
	return 0;
}

// Solution 2: A better approach
/*
	Basically this problem can be done in linear time complexity with
kadane's algorithm with also get the subarray which is giving the largest
positive sum.

Approach:
	a. We will have the following variables in the beginning.
	max_so_far, max_sum, start index and end index
	b. Traverse the array from starting and add the ith element to max_end_here
	now, we will check that adding the ith element gives greater value than max_do_far
	or not, if yes then we will update our max_so_far and also update starting and ending
	index (initially starting index is zero).
	c. Now in this step, we will print answer subarray using starting and ending variables
	d. Return the largest subarray sum that is : max_so_far
*/

#include <bits/stdc++.h>
using namespace std;

int maxSumSubArray(vector<int>& nums, vector<int> &subArray) {
	int max_so_far = INT_MIN;
	int max_end_here = 0;
	int start = 0;
	for (int i = 0; i < nums.size(); i++) {
		max_end_here += nums[i];
		if (max_end_here > max_so_far) {
			subArray.clear();
			max_so_far = max_end_here;
			subArray.push_back(start);
			subArray.push_back(i);
		}
		if (max_end_here < 0)
		{
			max_end_here = 0;
			start = i+1;
		}
	}
	return max_so_far;
}

// Time complexity: O(N)
