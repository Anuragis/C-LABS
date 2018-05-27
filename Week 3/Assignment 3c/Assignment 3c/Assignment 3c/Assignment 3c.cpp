// Assignment 3c.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

const int MAX_SIZE = 101;  // maximum size of the square matrix
const int MAX_START = 50;   // maximum starting number

void do_prime_spiral(const int n, const int start);
/**
Generates spiral matrix in counter-clockwise direction,
starts from the center of matrix.Within matrix 
'.' corresponds to composite number
'#' corresponds to prime number
@param n Size of Array matrix.
@param start Initial start value.
*/
void compute_primes(vector<char>  &input_vector, const int n, int start);
/**
Sets Composite Number indexes to false,
while Prime Number indexes are left true.
Calcuations done by using Sieve of Eratosthenes Algorithm.
@param input_arr The Input array for computing prime numbers.
*/

void move_right(vector<vector<char>> &input_vector, const int n, int&row, int&col, vector<char>&num_vector,int &pop_index , int&loop_len);
/**
Repeats till the length of loop_len
Increments pop_index by 1, moves right by incrementing column and keeping row constant and updates array element by elements of num_vector.
@param input_vector Input 2d Vector for computation
@param n Size of Array matrix.
@param row Current row in execution.
@param column Current column in execution.
@param num_vector Series vector containing prime and non prime indexes.
@param pop_index Index for popping num_vector.
@param loop_len Run loop until loop_len.
*/
void move_up(vector<vector<char>> &input_vector, const int n, int&row, int&col, vector<char>&num_vector, int &pop_index, int&loop_len);
/**
Repeats till the length of loop_len
Increments pop_index by 1, moves up by decrementing row and keeping column constant and updates array element by elements of num_vector.
@param input_vector Input 2d Vector for computation
@param n Size of Array matrix.
@param row Current row in execution.
@param column Current column in execution.
@param num_vector Series vector containing prime and non prime indexes.
@param pop_index Index for popping num_vector.
@param loop_len Run loop until loop_len.
*/
void move_left(vector<vector<char>> &input_vector, const int n, int&row, int&col, vector<char>&num_vector, int &pop_index, int&loop_len);
/**
Repeats till the length of loop_len
Increments pop_index by 1, moves left by decrementing column and keeping row constant and updates array element by elements of num_vector.
@param input_vector Input 2d Vector for computation
@param n Size of Array matrix.
@param row Current row in execution.
@param column Current column in execution.
@param num_vector Series vector containing prime and non prime indexes.
@param pop_index Index for popping num_vector.
@param loop_len Run loop until loop_len.
*/
void move_down(vector<vector<char>> &input_vector, const int n, int&row, int&col, vector<char>&num_vector, int &pop_index, int&loop_len);
/**
Repeats till the length of loop_len
Increments pop_index by 1, moves right by incrementing row and keeping column constant and updates array element by elements of num_vector.
@param input_vector Input 2d Vector for computation
@param n Size of Array matrix.
@param row Current row in execution.
@param column Current column in execution.
@param num_vector Series vector containing prime and non prime indexes.
@param pop_index Index for popping num_vector.
@param loop_len Run loop until loop_len.
*/

void print_matrix(vector<vector<char>> &input_vector, int n);
/**
Prints Sprial Matrix
@param arr Input 2d Array for computation
@param n Size of Array matrix.
*/


/**
* The main: Generate and print prime spirals of various sizes.
*/
int main()
{
	do_prime_spiral(5, 1);
	do_prime_spiral(25, 11);
	do_prime_spiral(35, 0);
	do_prime_spiral(50, 31);
	do_prime_spiral(101, 41);
	return 0;
}

void do_prime_spiral(const int n, const int start) {
	cout << "Prime spiral of size " << n << " starting at " << start << endl;

	if ((n % 2) == 0 || (start < 1 ||start > MAX_SIZE)) {
		if ((n % 2) == 0) {
			cout << "***** Error: Size " << n << " must be odd." << endl;
			cout << endl;
		}
		else {
			cout << "***** Error: Starting value "<< start <<" < 1 or > 50" << endl;
			cout << endl;
		}

	}
	else {
		vector<char> num_vector((n*n)+start,'#');

		compute_primes(num_vector,n,start);

		vector<vector<char>> input_vector(n, vector<char>(n, '.'));
		int row = n / 2; // Middle Row index
		int col = n / 2; // Middle Column index
		input_vector[row][col] = num_vector[start];
		int pop_index = start; //Initialize number series
		int loop_len = 1;// moves per direction

						 //run spiral loop until boundary conditions are met
		while ((row < n && row >= 0) && (col < n && col >= 0)) {

			move_right(input_vector, n, row, col, num_vector, pop_index, loop_len);
			move_up(input_vector, n, row, col, num_vector, pop_index, loop_len);

			loop_len += 1;// increment loop length.

			move_left(input_vector, n, row, col, num_vector, pop_index, loop_len);
			move_down(input_vector, n, row, col, num_vector, pop_index, loop_len);

			loop_len += 1;// increment loop length.
		}
		print_matrix(input_vector, n);
	}
}


void compute_primes(vector<char>  &input_vector, const int n, int start) {
	int k = 1; // Multiplying factor.
	input_vector[0] = '.';
	input_vector[1] = '.';
	for (int i = 2; i*i < n*n+start; i++) {
		if (input_vector[i] == '#') {
			for (int j = i*i; j < n*n + start; j = i*i + i*k++) {
				input_vector[j] = '.';
			}
			k = 1;
		}
	}
}

void print_matrix(vector<vector<char>> &input_vector, int n) {
	cout << endl;
	for (int row = 0;row < n;row++) {
		for (int col = 0; col < n;col++) {
			cout << input_vector[row][col];
		}
		cout << endl;
	}
	cout << endl;
}

void move_right(vector<vector<char>> &input_vector, const int n, int&row, int&col, vector<char>&num_vector, int &pop_index, int&loop_len) {
	if (row < n && row >= 0) {
		for (int incr = 0; incr < loop_len;incr++) {
			++col;
			if (col >= 0 && col < n) {
				pop_index++;
				input_vector[row][col] = num_vector[pop_index];
			}
		}
	}
}

void move_up(vector<vector<char>> &input_vector, const int n, int&row, int&col, vector<char>&num_vector, int &pop_index, int&loop_len) {
	if (col < n && col >= 0) {
		for (int incr = 0; incr < loop_len;incr++) {
			if (row != n) {
				--row;
			}
			if (row >= 0 && row<n) {
				pop_index++;
				input_vector[row][col] = num_vector[pop_index];
			}
		}
	}
}

void move_left(vector<vector<char>> &input_vector, const int n, int&row, int&col, vector<char>&num_vector, int &pop_index, int&loop_len) {
	if (row < n && row >= 0) {
		for (int incr = 0; incr < loop_len;incr++) {
			if (col != n) {
				--col;
			}
			if (col >= 0 && col<n) {
				pop_index++;
				input_vector[row][col] = num_vector[pop_index];
			}
		}
	}
}

void move_down(vector<vector<char>> &input_vector, const int n, int&row, int&col, vector<char>&num_vector, int &pop_index, int&loop_len) {
	if (col < n && col >= 0) {
		for (int incr = 0; incr < loop_len;incr++) {
			++row;
			if (row >= 0 && row<n) {
				pop_index++;
				input_vector[row][col] = num_vector[pop_index];
			}
		}
	}
}
