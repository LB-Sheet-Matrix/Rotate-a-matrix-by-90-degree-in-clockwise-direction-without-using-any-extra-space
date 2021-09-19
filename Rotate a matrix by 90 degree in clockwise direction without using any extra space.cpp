/*

Method 1

Approach: The approach is similar to Inplace rotate square matrix by 90 degrees | Set 1. The only thing that is different is to print the elements of the cycle in a clockwise direction i.e. An N x N matrix will have floor(N/2) square cycles. 
For example, a 3 X 3 matrix will have 1 cycle. The cycle is formed by its 1st row, last column, last row, and 1st column. 
For each square cycle, we swap the elements involved with the corresponding cell in the matrix in the clockwise direction. We just need a temporary variable for this.

Explanation:



Let size of row and column be 3.
 
During first iteration – 

a[i][j] = Element at first index (leftmost corner top)= 1.
a[j][n-1-i]= Rightmost corner top Element = 3.
a[n-1-i][n-1-j] = Rightmost corner bottom element = 9.
a[n-1-j][i] = Leftmost corner bottom element = 7.
Move these elements in the clockwise direction.
 
During second iteration – 

a[i][j] = 2.
a[j][n-1-j] = 6.
a[n-1-i][n-1-j] = 8.
a[n-1-j][i] = 4. 
Similarly, move these elements in the clockwise direction. 

Below is the implementation of the above approach: 

*/

// C++ implementation of above approach
#include <bits/stdc++.h>
using namespace std;
 
#define N 4
 
// Function to rotate the matrix 90 degree clockwise
void rotate90Clockwise(int a[N][N])
{
 
    // Traverse each cycle
    for (int i = 0; i < N / 2; i++) {
        for (int j = i; j < N - i - 1; j++) {
 
            // Swap elements of each cycle
            // in clockwise direction
            int temp = a[i][j];
            a[i][j] = a[N - 1 - j][i];
            a[N - 1 - j][i] = a[N - 1 - i][N - 1 - j];
            a[N - 1 - i][N - 1 - j] = a[j][N - 1 - i];
            a[j][N - 1 - i] = temp;
        }
    }
}
 
// Function for print matrix
void printMatrix(int arr[N][N])
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << arr[i][j] << " ";
        cout << '\n';
    }
}
 
// Driver code
int main()
{
    int arr[N][N] = { { 1, 2, 3, 4 },
                      { 5, 6, 7, 8 },
                      { 9, 10, 11, 12 },
                      { 13, 14, 15, 16 } };
    rotate90Clockwise(arr);
    printMatrix(arr);
    return 0;
}

/*
Output

13 9 5 1 
14 10 6 2 
15 11 7 3 
16 12 8 4

*/ 
