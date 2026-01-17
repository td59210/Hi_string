#include <iostream>
#include <cassert>
#include <string>

using namespace std;

int strcmp_case_insensitive(string one, string two) {

	//setting initial values
	int aValue1 = 0;
	int aValue2 = 0;
	int i = 0;

	for (short s : one) //taking characters from first string
	{
		if (tolower(s) == tolower(two[i])) //comparing to first charcter in second string
		{
			i++; //adds 1 to i if above is true
		}

		aValue1 += static_cast<int>(one[i]); //add ascii to aValue
		aValue2 += static_cast<int>(two[i]);

	} //repeats with rest of characters

	if (one.length() == i) //compare length of string one to i value
	{
		return 0;
	}
	else if (aValue1 > aValue2) {
		return 1;
	}
	else if (aValue1 < aValue2) {
		return -1;
	}
}


int main() {
	string s1;
	cout << "Hello, please enter a word. \n";
	cin >> s1;

	string s2;
	cout << "Enter another word. \n";
	cin >> s2;

	cout << "The comparison of " << s1 << " and " << s2 << " returns " << strcmp_case_insensitive(s1, s2) << "\n";


}

