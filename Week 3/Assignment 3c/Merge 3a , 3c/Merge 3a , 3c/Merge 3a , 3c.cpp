// Assignment 3b.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

const int MAX_NUMBER = 1000;// Max size of sequence of numbers.
							/***** Complete this program. *****/

void do_prime_spiral(const int n, const int start);

void arr_initialzer(vector<string> &input_vector);

void compute_primes(vector<string> &input_vector);

void print_primes(vector<string>  &input_vector);
/**
* The main: Generate and print prime spirals of various sizes.
*/


int main()
{

	//do_prime_spiral(5, 1);
	/**do_prime_spiral(25, 11);
	do_prime_spiral(35, 0);
	do_prime_spiral(50, 31);
	do_prime_spiral(101, 41);*/

	vector<vector<string>> a;
	return 0;
}

void do_prime_spiral(const int n, const int start) {

	vector<string> input_vector;
		
	arr_initialzer(input_vector);

	compute_primes(input_vector);

	 print_primes(input_vector);
}

void arr_initialzer(vector<string> &input_vector) {

	input_vector.push_back(".");
	input_vector.push_back(".");
	for (int i = 2;i < MAX_NUMBER + 1;i++) {
		input_vector.push_back("#");
	}
}

void compute_primes(vector<string>  &input_vector) {
	int k = 1; // Multiplying factor.
	for (int i = 2; i < sqrt(MAX_NUMBER); i++) {
		if (input_vector[i] == "#") {
			for (int j = i*i; j < MAX_NUMBER + 1; j = i*i + i*k++) {
				input_vector[j] = ".";
			}
			k = 1;
		}
	}
}

void print_primes(vector<string>  &input_vector) {

	for (int i = 0;i < MAX_NUMBER + 1;i++) {
		cout << setw(2) << input_vector[i];

	}
}