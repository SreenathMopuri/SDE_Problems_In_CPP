/*
Stock Buy and Sell
Problem Statement:
	You are given an array of prices where prices[i] is the price 
of a given stock on an ith day.
	You want to maximize your profit by chossing a single day to buy and
choosing a different day in the future to sell that stock. Return the maximum
profit you can achieve from this transaction. If you cannot achieve any profit
return 0.

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and 
sell on day 5 (price = 6), profit = 6-1 = 5.

Note: That buying on day 2 and selling on day 1 
is not allowed because you must buy before 
you sell.

Example 2:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are 
done and the max profit = 0.
*/
// Solution1 : Brute Force
/*
	We can simply use 2 loops and track every transaction and maintain a
variable maxPro to contain the max value among all transactions.
Approach:
	a.	Use a for loop of 'i' from 0 to n
	b.	Use another for loop of j from 'i+1' to n
	c.	If arr[j] > arr[i], take the difference and compare and store it in the
	maxPro variable.
	d.	Return maxPro.

*/
#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int> &arr) {
	int maxPro = 0;
	int n = arr.size();

	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			if (arr[j] > arr[i]) {
				maxPro = max(arr[j]-arr[i], maxPro);
			}
		}
	}
	return maxPro;
}
// Time complexity: O(n^2)
int main() {
	vector<int> arr = {7, 1, 5, 3, 6, 4};
	int maxPro = maxProfit(arr);
	cout << "Max Profit is: " << maxPro << endl;
	return 0;
}

// Solution2: Optimal solution
/*
Approach:
	a.	Create a variable maxPro and store 0 initially.
	b.	Create a variable minPrice and store some larger value (ex:INT_MAX)
	c.	Run a for loop from 0 to n
	d.	Update the minPrice if it is greater that current element of the array
	e.	Take the difference of the minPrice with the current element of the array
	compare and maintain it in maxPro.
	f.	Return the maxPro.
*/
int maxProfit_OP(vector<int> &nums) {
	int maxPro = 0;
	int n = arr.size();
	int minPrice = INT_MAX;

	for (int i = 0; i < n; i++) {
		minPrice = min(minPrice, arr[i]);
		maxPro = max(maxPro, arr[i]-minPrice);
	}
	return maxPro;
}
// Time complexity: O(N)
