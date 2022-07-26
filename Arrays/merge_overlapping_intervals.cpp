/*
Merge Overlapping Sub-Intervals
Problem Statement:
	Given an array of intervals, merge all the overlapping intervals
and return an array of non-overlapping intervals.
Example 1: 

Input: intervals=[[1,3],[2,6],[8,10],[15,18]]

Output: [[1,6],[8,10],[15,18]]

Explanation: Since intervals [1,3] and [2,6] are overlapping we can merge them to form [1,6]
 intervals.

Example 2:

Input: [[1,4],[4,5]]

Output: [[1,5]]

Explanation: Since intervals [1,4] and [4,5] are overlapping we can merge them to form [1,5].
*/

// Solution1: Brute Force
/*
Approach:
	First check whether the array is sorted or not. If not sort the array.
Now linearly iterate over the array and then check for all of its next intervals
whether they are overlapping with the interval at the current index. Take a new data
structure and insert the overlapped interval. While iterating if the interval lies
in the interval present in the data structure simply continue and move to the next
interval.
*/
#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int> > merge(vector<pair<int, int>> &arr) {
	int n = arr.size();
	sort(arr.begin(), arr.end());

	vector<pair<int, int>> ans;

	for (int i = 0; i < n; i++) {
		int start = arr[i].first;
		int end = arr[i].second;

		// since the intervals already lies in the data structure
		if(!ans.empty()) {
			if (start <= ans.back().second)
				continue;
		}

		for (int j = i+1; j < n; j++) {
			if (arr[j].first <= end) {
				end = max(end, arr[j].second);
			}
		}
		end = max(end, arr[i].second);
		ans.push_back({start, end});
	}
	return ans;
}
// Time complexity : O(NlogN) + O(N*N)
// Space complexity: O(N)
int main() {
	vector<pair<int, int>> arr;
	arr = {{1, 3}, {2, 4}, {2, 6}, {8, 9}, {9, 11},
			{15, 18}, {16, 17}};
	vector<pair<int, int>> ans = merge(arr);
	cout << "Merged Overlapping intervals are: " << endl;
	for (auto it : ans) {
		cout << it.first << " " << it.second << endl;
	}
	return 0;
}

// Solution2: Optimal approach
/*
Approach:
	Since we have sorted intervals, the intervals which will be merging are
bound to be adjacent. We kept on merging simultaneously as we were traversing
through the array and when the element was non-overlapping we simply inserted
the element in out data structure.
*/
vector<pair<int, int>> merge(vector<pair<int, int>> &arr) {
	sort(arr.begin(), arr.end());

	vector<pair<int, int>> ans;

	for (int i = 0; i < arr.size(); i++) {
		if (ans.empty() || ans.back().second < arr[i].first) {
			ans.push_back({arr[i].first, arr[i].second});
		} else {
			ans.back().second = max(ans.back().second, arr[i].second);
		}
	}
	return ans;
}
