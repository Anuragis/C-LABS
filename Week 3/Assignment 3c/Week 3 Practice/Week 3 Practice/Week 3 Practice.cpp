#include <iostream>
#include <vector>
using namespace std;

#include <string>
using namespace std;

/**
Return a string that mixes the characters in strings a and b.
If one string is longer than the other, append the suffix.
For example, mixing "San" and "Francisco" yields "SFarnancisco".
*/
string mix(string, string);

string mix(string a, string b)
{
	if (a.length()<b.length()) {
		return a[0] + b;
	}else if(a.length()>b.length()){
		return a + b[0];
	}
	else {
		return "equal";
	}
}


int main()
{
	cout << mix("San", "Fransisco");
}