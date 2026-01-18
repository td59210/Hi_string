#include <iostream>
#include <cassert>
#include <string>
#include <cctype>

using namespace std;

int strcmp_case_insensitive(const string one, const string two)
{

	//setting initial values
	int i = 0;

	//start at first character, only continue if inside both strings, loop for each character
	for (i = 0; i < one.length() && i < two.lenght(); i++) 
	{
		char s1 = tolower(one[i]); //lowercase characters
		char s2 = tolower(two[i]);

		//loop to check characters--will stop if a differnce is found
		if (s1 > s2) {

			return 1;
		}
		else if (s1 < s2) {
			
			return -1;
		}

	}
	//checks length after the character loop finishes running and no difference is found
	if (one.length() == two.length()) {

		return 0;
	}
	else if (one.length() > two.length()) {
		
		return 1;
	}
	else {
		
		return -1;
	}
}


int main() {

//automatic tests

	//tests for equal
	assert(strcmp_case_insensitive("Hi", "hi") == 0);
	assert(strcmp_case_insensitive("HEY", "hey") == 0);
	assert(strcmp_case_insensitive("", "") == 0);
	
	//tests for less than 0
	assert(strcmp_case_insensitive("bus", "car") < 0); //first is alphabetically earlier
	assert(strcmp_case_insensitive("abc", "abcde") < 0); //first is shorter
	assert(strcmp_case_insensitive("", "cat") < 0);

	//tests for greater than 0
	assert(strcmp_case_insensitive("zebra", "tiger") > 0);
	assert(strcmp_case_insensitive("bananas", "banana") > 0);
	assert(strcmp_case_insensitive("cat", "") > 0);


//user input:
	string c1;
	cout << "Hello, please enter a word. \n";
	cin >> c1;

	string c2;
	cout << "Enter another word. \n";
	cin >> c2;

	cout << "The comparison of " << c1 << " and " << c2 << " returns " << strcmp_case_insensitive(c1, c2) << "\n";

}

