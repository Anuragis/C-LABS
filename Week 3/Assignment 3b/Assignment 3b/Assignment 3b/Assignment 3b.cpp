// Assignment 3b.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <iomanip>
using namespace std;
const int MAX_SIZE = 101;  // maximum size of the square matrix
const int MAX_START = 50;   // maximum starting number


void do_spiral(const int n, const int start);
/**
Generates spiral matrix in counter-clockwise direction,
starts from the center of matrix with starting value as start
@param n Size of Array matrix.
@param start Initial start value.
*/
void move_right(int arr[][MAX_SIZE], const int n, int&row, int&col, int&num, int&loop_len);
/**
Repeats till the length of loop_len
Increments number series by 1, moves right by incrementing column and keeping row constant and updates array element by number series
@param arr Input 2d Array for computation
@param n Size of Array matrix.
@param row Current row in execution.
@param column Current column in execution.
@param num Current value of number series.
@param loop_len Run loop until loop_len.
*/
void move_up(int arr[][MAX_SIZE], const int n, int&row, int&col, int&num, int&loop_len);
/**
Repeats till the length of loop_len
Increments number series by 1, moves up by decrementing row and keeping column constant and updates array element by number series
@param arr Input 2d Array for computation
@param n Size of Array matrix.
@param row Current row in execution
@param column Current column in execution.
@param num Current value of number series.
@param loop_len Run loop until loop_len.
*/

void move_left(int arr[][MAX_SIZE], const int n, int&row, int&col, int&num, int&loop_len);
/**
Repeats till the length of loop_len
Increments number series by 1, moves right by decrementing column and keeping row constant and updates array element by number series
@param arr Input 2d Array for computation
@param n Size of Array matrix.
@param row Current row in execution
@param column Current column in execution.
@param num Current value of number series.
@param loop_len Run loop until loop_len.
*/

void move_down(int arr[][MAX_SIZE], const int n, int&row, int&col, int&num, int&loop_len);
/**
Repeats till the length of loop_len
Increments number series by 1, moves down incrementing row and keeping column constant and updates array element by number series
@param arr Input 2d Array for computation
@param n Size of Array matrix.
@param row Current row in execution
@param column Current column in execution.
@param num Current value of number series.
@param loop_len Run loop until loop_len.
*/

void print_matrix(int arr[][MAX_SIZE], const int n);
/**
Prints Sprial Matrix
@param arr Input 2d Array for computation
@param n Size of Array matrix.
*/
int main()
{
	do_spiral(1, 1);
	do_spiral(5, 1);
	do_spiral(9, 11);
	do_spiral(12, 13);
	do_spiral(15, 17);

	return 0;
}

void do_spiral(const int n, const int start) {
	
	cout << "Spiral of size " << n << " starting at " << start << endl;

	// check if size is odd
	if ((n % 2) == 0 || start>50) {
		if((n % 2) == 0){
			cout << "***** Error: Size " << n << " must be odd." << endl;
			cout << endl;
		}
		else {
			cout << "***** Error: Start " << start << " must be smaller than 51." << endl;
			cout << endl;
		}

	}
	else{
		
		int arr[MAX_SIZE][MAX_SIZE]; // Initial Array
		int row = n / 2; // Middle Row index
		int col = n / 2; // Middle Column index
		arr[row][col] = start; 
		int num_series = start; //Initialize number series
		int loop_len = 1;// moves per direction

		//run spiral loop until boundary conditions are met
		while ((row < n && row >=0) && (col < n && col >= 0)) {

			move_right(arr, n, row, col, num_series, loop_len);
			move_up(arr, n, row, col, num_series, loop_len);

			loop_len += 1;// increment loop length.

			move_left(arr, n, row, col, num_series, loop_len);
			move_down(arr, n, row, col, num_series, loop_len);

			loop_len += 1;// increment loop length.
		}
			print_matrix(arr, n);
	}
}

void move_right(int arr[][MAX_SIZE], const int n, int&row, int&col, int&num, int&loop_len) {
	if (row < n && row >=0) {
		for (int incr = 0; incr < loop_len;incr++) {
			++col;
			if (col >= 0 && col < n) {
				num++;
				arr[row][col] = num;
			}
		}
	}
}

void move_up(int arr[][MAX_SIZE], const int n, int&row, int&col, int&num, int&loop_len) {
	if (col < n && col>= 0) {
		for (int incr = 0; incr < loop_len;incr++) {
			if (row != n) {
				--row;
			}
			if (row >= 0 && row<n) {
				num++;
				arr[row][col] = num;
			}
		}
	}
}

void move_left(int arr[][MAX_SIZE], const int n, int&row, int&col, int&num, int&loop_len) {
	if (row < n && row >= 0) {
		for (int incr = 0; incr < loop_len;incr++) {
			if (col != n) {
				--col;
			}
			if (col >= 0 && col<n) {
				num++;
				arr[row][col] = num;
			}
		}
	}
}

void move_down(int arr[][MAX_SIZE], const int n, int&row, int&col, int&num, int&loop_len) {
	if (col < n && col >= 0) {
		for (int incr = 0; incr < loop_len;incr++) {
			++row;
			if (row >= 0 && row<n) {
				num++;
				arr[row][col] = num;
			}
		}
	}
}

void print_matrix(int arr[][MAX_SIZE], const int n) {
	cout << endl;
	for (int row = 0;row < n;row++) {
		for (int col = 0; col < n;col++) {
			cout << setw(4) << arr[row][col];
		}
		cout << endl;
	}
	cout << endl;
}