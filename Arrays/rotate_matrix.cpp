/*
Rotate Image by 90 degree
Problem Statement:
	Given Matrix, your task is to rotate the matrix 90 degrees clockwise.
Example 1:

Input: [[1,2,3],[4,5,6],[7,8,9]]

Output: [[7,4,1],[8,5,2],[9,6,3]]

Explanation: Rotate the matrix simply by 90 degree clockwise and return the matrix.

Example 2:

Input: [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]

Output:[[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]

Explanation: Rotate the matrix simply by 90 degree clockwise and return the matrix
*/
// Solution1: Brute Force
/*
Approach: Take another dummy matrix of n*n, and then take first row of the matrix
and put it in the last column of the dummy matrix, take the second row of matrix,
and put it in second last column of the matrix and so.
*/

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> rotate(vector<vector<int>> &matrix) {
	int n = matrix.size();
	vector<vector<int>> rotated(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			rotated[j][n-i-1] = matrix[i][j];
		}
	}
	return rotated;
}
// Time complexity: O(N*N)
// Space complexity: O(N*N)
void printMatrix(vector<vector<int>> &matrix) {
	int n = matrix.size();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int main() {
	vector<vector<int>> arr;
	arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	vector<vector<int>> rotated = rotate(arr);
	printMatrix(rotated);
	return 0;
}

// Solution 2: Optimized approach
/*
Approach: Using Transpose the matrix
	a.	Transpose of the matrix (transposing means changing columns to rows
	rows to colums).
	b.	Reverse each row of the matrix
*/

void rotate(vector<vector<int>> &matrix) {
	int n =  matrix.size();
	// transposing the matrix
	for (int i = 0; i < n; i++) {
		for(int j = 0; j < i; j++) {
			swap(matrix[i][j], matrix[j][i]);
		}
	}

	// reversing each row of the matrix
	for (int i = 0; i < n; i++) {
		std::reverse(matrix[i].begin(), matrix[i].end());
	}
}
// Time complexity: O(N*N)
