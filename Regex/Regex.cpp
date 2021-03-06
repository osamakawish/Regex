// Regex.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"

using namespace std;

// Testing regex matches.
bool match(string s, string pattern) {

	regex p = regex(pattern);

	cout << "String: \t\t\"" << s << "\"" << endl;
	cout << "Pattern:\t\t\"" << pattern << "\"" << endl;

	if (regex_match(s, p)) {
		cout << "Match found." << endl << endl;
		return true;
	}

	cout << "Match not found." << endl << endl;
	return false;
}

bool searchCapture(string s, string pattern) {
	smatch result;
	regex p = regex(pattern);
	bool toReturn = regex_search(s, result, p);

	cout << "String: \t\t\"" << s << "\"" << endl;
	cout << "Pattern:\t\t\"" << pattern << "\"" << endl;

	for (int i = 0; i < result.size(); i++)
	{
		cout << "Capture Group " << i << ":\t\"" << result[i] << "\"" << endl;
	}

	if (toReturn) { cout << "Match found."; }
	else { cout << "Match not found."; }

	cout << endl << endl;

	return toReturn;
}

int main()
{
	// Basic regex matches.
	match("Hello", "Hello");		// Found
	match("Ha", "H.");				// Found
	match("H", "H.");				// Not found
	match("Hunt", "Hu[rn]t");		// Found
	match("Hurt", "Hu[rn]t");		// Found
	match("Hust", "Hu[rn]t");		// Not found
	match("Burn", "Burnt*");		// Found
	match("Burnt", "Burnt*");		// Found
	match("Burns", "Burnt*");		// Not found
	match("Husk", "Hu(s.|(r|n)t)");	// Found
	match("Husk", "Hu(s.|[rn]t)");	// Found
	
	// Useful regex matches.
	// TODO: Figure out how to use capture groups.
	searchCapture("abcdefg", "x");
	searchCapture("abcdefg", "a");
	searchCapture("username@gmail.com", "(.*)@(.*)\.(net|com|ca)");

	/*string seq = "foo@helloworld.com";
	regex rgx("(.*)@(.*)");
	smatch result;
	regex_search(seq, result, rgx);
	for (size_t i = 0; i<result.size(); ++i)
	{
		cout << result[i] << endl;
	}*/

    return 0;
}

