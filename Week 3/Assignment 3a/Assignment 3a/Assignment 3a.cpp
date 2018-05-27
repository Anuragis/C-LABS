// Assignment 3a.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

const int MAX_NUMBER = 1000;// Max size of sequence of numbers.

const int NUMBERS_PER_LINE = 20; // Max sequence of numbers printed per line in output.

void arr_initialzer(bool[]);
/**
Initializes input boolean array to default value true.
@param input_arr The array to be initialized.
*/


void compute_primes(bool []);
/**
Sets Composite Number indexes to false,
while Prime Number indexes are left true.
Calcuations done by using Sieve of Eratosthenes Algorithm.
@param input_arr The Input array for computing prime numbers.
*/

void print_primes(bool[]);
/**
Prints the prime number indexes.
@param input_arr The Input array passed for printing.
*/


int main()
{
	bool seq_arr[MAX_NUMBER +1];

//Initialize the seq_arr to default value true.
	arr_initialzer(seq_arr);

// Computute prime numbers
	compute_primes(seq_arr);

// Print prime numbers
	print_primes(seq_arr);
    
	return 0;
}


void arr_initialzer(bool input_arr[]) {
	for (int i = 2;i < MAX_NUMBER+1;i++) {
		input_arr[i] = true;
	}
}

void compute_primes(bool input_arr[]) {
	int k = 1; // Multiplying factor.
	for (int i = 2; i < sqrt(MAX_NUMBER); i++) {
		if (input_arr[i]) {
			for (int j = i*i; j < MAX_NUMBER +1; j = i*i + i*k++) {
				input_arr[j] = false;
			}
			k = 1;
		}
	}
}

void print_primes(bool input_arr[]) {

	int check_number_count = 0;

		for (int i = 2;i < MAX_NUMBER+1;i++) {
			if (input_arr[i]) {
				if (check_number_count == MAX_NUMBER) {
					cout << endl;
					check_number_count = 0;
				}
				cout <<setw(4)<<i;
				check_number_count++;
			}
		}
}