// Week 4.cpp : Defines the entry point for the console application.
//

#include <iostream>
using namespace std;




void print_array(int a[], int n)
{
	if (n == 0) { cout << "{}" << endl; return; }
	cout << "{ ";
	for (int i = 0; i < n; i++)
	{
		if (i > 0) cout << ", ";
		cout << a[i];
	}
	cout << " }" << endl;
}

int* firstneg(int* begin, int* end)
{

	cout << "Hi"<<*(end);
	return NULL;
}
int main()
{
	int a[] = { 1, 4, -9, -16, -25, -36, 49, -64, 81, 100, -121 };
	int* p = firstneg(a, a + 10);
	cout << p - a << endl;
	cout << "Expected: 2" << endl;
	p = firstneg(a + 5, a + 10);
	cout << p - a << endl;
	cout << "Expected: 5" << endl;
	p = firstneg(a + 8, a + 10);
	cout << p << endl;
	cout << "Expected: 0" << endl;
	return 0;
}