/*
Generate Pascal's Triangle
Input Format: N = 5

Result:
    1
   1 1
  1 2 1
 1 3 3 1
1 4 6 4 1

Explanation: There are 5 rows in the output matrix. 
Each row corresponds to each one of the rows in the image shown above.
*/
// solution
/*
Approach:
	To solve the problem, we need to first create an array of size N or
numRows (input value). This array is used to store each of the rows expected
in the output, so, for example array[1] = [1, 1]. In this array, the number of
columns (say, numCols) is equal to the number of the i-th row+1 (since, o-indexed)
i.e., for 0-th row, numCols=1. So, the number of columns is different for each row.

Next, we need to run a loop from i = 0 to numRows-1 (inclusive) in order to store each
row in our array. For each of iteration of this loop, we follow the below steps:
	a. Create an array of size (i+1) (for some languages such as C++, you need to create a 2D
	array at the start of the program and resize array[i] to (i+1)).
	b. Set the first and last value of array[i] to 1.
	c. Run another loop from j = 1 to i - 1(inclusive) and for each iteration put array[i][j] =
	array[i-1][j-1] + array[i-1][j].

After iterating numRows times, you return the array.

DryRun: Let's do a dry run to understand it in a much better way.

*/
#include <iostream>
using namespace std;

class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> r(numRows);
		for (int i = 0; i < numRows; i++) {
			r[i].resize(i+1);
			r[i][0] = r[i][i] = 1;
			for (int j = 1; j < i; j++) {
				r[i][j] = r[i-1][j-1] + r[i-1][j];
			}
		}
		return r;
	}
};

// Time complexity: O(numRows^2)
int main()
{
	int numRows = 5;
	Solution sol;
	vector<vector<int>> rows = sol.generate(numRows);
	return 0;
}
