/*
Set Matrix Zero
	Given a matrix if an element in the matrix is 0 then you will have to 
set its entire column and row to 0 and then return the matrix.

Example:
Input: matrix=[[1,1,1],[1,0,1],[1,1,1]]

Output: [[1,0,1],[0,0,0],[1,0,1]]

Explanation: Since matrix[2][2]=0.Therfore the 2nd column and 2nd row wil be set to 0.

*/

// Solution 1:
/*
Approach: Using Brute Force
	Assuming all the elements in the matrix are non-negative. Traverse through
the matrix and if you find an element with value 0, then change all the elements
in its row and column to -1. except when an element is 0. The reason for not changing
other elements to 0, but -1, because that might affect other columns and rows.
Now traverse through the matrix again and if an element is -1 chnage to 0.
*/

#include <bits/stdc++.h>
using namespace std;

void setZeros(vector<vector<int>> &matrix) {
	int rows = matrix.size();
	int cols = matrix[0].size();
	for (int row = 0; row < rows; row++) {
		for (int col = 0; col < cols; col++) {
			if (matrix[row][col] == 0) {
				int indx = row - 1;
				while (indx >= 0) {
					if (matrix[indx][col] != 0) {
						matrix[indx][col] = -1;
					}
					indx--;
				}
				indx = row + 1;
				while (indx < rows) {
					if (matrix[indx][col] != 0) {
						matrix[indx][col] = -1;
					}
					indx++;
				}
				indx = col-1;
				while(indx >= 0) {
					if (matrix[row][indx] != 0) {
						matrix[row][indx] = -1;
					}
					indx--;
				}
				indx = col + 1;
				while (indx < cols) {
					if (matrix[row][indx] != 0) {
						matrix[row][indx] = -1;
					}
					indx++;
				}
			}
		}
	}

	for (int row = 0; row < rows; row++) {
		for (int col = 0; col < cols; col++) {
			if (matrix[row][col] < 0) {
				matrix[row][col] = 0;
			}
		}
	}
}

void printMatrix(vector<vector<int>> &matrix) {
	for (int row = 0; row < matrix.size(); row++) {
		for (int col = 0; col < matrix[0].size(); col++) {
			cout << matrix[row][col] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int main() {
	vector<vector<int>> arr;
	arr = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
	setZeros(arr);
	printMatrix(arr);
	return 0;
}

// Time Complexity: O((N*M)*(N+M). O(N*M) for traversing through each
// element and (N+M) for traversing to row and column of elements having value 0.

// Solution2: Better Approach
/*
	Instead of traversing through each row and column, we can use dummy arrays
to check if the particular row or column has an element 0 or not, which will improve
the time complexity.
	Take two dummy array one of size of row and other size of column. Now
traverse through the array. If Matrix[i][j] == 0 then set dummy1[i] = 0(for row)
and dummy2[j] = 0 (for column). Now traverse through the array again and if dummy1[i] == 0
|| dummy2[j] == 0 then arr[i][j] = 0, else continue.
*/
#include<iostream>

void setMatrixZeros(vector<vector<int>> &matrix) {
	int rows = matrix.size();
	int cols = matrix[0].size();
	vector<int> dummy1(rows, -1);
	vector<int> dummy2(cols, -1);

	for (int i = 0; i <rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (matrix[i][j] == 0) {
				dummy2[j] = 0;
				dummy1[i] = 0;
			}
		}
	}

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (dummy1[i] == 0 || dummy2[j] == 0) {
				matrix[i][j] = 0;
			}
		}
	}
}

// Time Complexity: O(N*M + N*M)
// Space Complexity : O(N)

// Solution3
/*
	Instead of taking two separate dummy array, take first row and colum of the matrix
as array for checking whether the particular column or row has the value 0 or
not. Since Matrix[0][0] are overlapping. Therefore take separate variable col0(say) to check
if the 0th column has 0 or not and use matrix[0][0] to check if the 0th row
has 0 or not. Now traverse from last element to the first element and check if matrix[i][0] == 0||
matrix[0][j] == 0 and if true set matrix[i][j] = 0, else continue
*/

#include<iostream>

void setMatrixZeros(vector<vector<int>> &matrix) {
	int rows = matrix.size();
	int cols = matrix[0].size();
	int col0 = 1;
	for (int i = 0; i < rows; i++) {
		// checking if 0 is present in the 0th column or not
		if (matrix[i][0] == 0) col0 = 0;
		for (int j = 1; j < cols; j++) {
			if (matrix[i][j] == 0) {
				matrix[i][0] = 0;
				matrix[0][j] = 0;
			}
		}
	}

	// Traversing in the reverse direction and checking if the row or col
	// has 0 or not, and setting values of matrix accordingly.
	for (int i = rows-1; i >= 0; i--) {
		for (int j = cols-1; j >= 0; j--) {
			if (matrix[i][0] == 0 || matrix[0][j] == 0) {
				matrix[i][j] = 0;
			}
		}
		if (col0 == 0) {
			matrix[i][0] = 0;
		}
	}
}
