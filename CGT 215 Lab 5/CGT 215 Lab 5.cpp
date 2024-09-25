// CGT 215 Lab 5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

const std::vector<char> cypherTable = { 'V', 'F', 'X', 'B', 'L', 'I', 'T', 'Z', 'J', 'R', 'P', 'H', 'D', 'K', 'N', 'O', 'W', 'S', 'G', 'U', 'Y', 'Q', 'M', 'A', 'C', 'E' };

void translateText(std::vector<int>& input) {
	for (size_t i = 0; i < input.size(); ++i) {
		int c = input[i];

		if (c >= 65 && c <= 90) {
			input[i] = cypherTable[c - 65];
		}
		else if (c >= 97 && c <= 122) {
			int upperCaseLetter = c - 32;
			char upperCaseCode = cypherTable[upperCaseLetter - 65];
			input[i] = upperCaseCode + 32;
		}
	}
}

int main() {
	std::vector<int> text;
	char ch;
	int count = 0;

	std::cout << "Input text to cypher: ";
	while (count < 128 && std::cin.get(ch) && ch != '\n') {
		text.push_back(static_cast<int>(ch));
		count++;
	}

	translateText(text);

	std::cout << "Encoded Message: ";
	for (int c : text) {
		std::cout << static_cast<char>(c);
	}
	std::cout << std::endl;

	return 0;
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
