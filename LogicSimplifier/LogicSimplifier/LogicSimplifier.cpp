// LogicSimplifier.cpp : does things
//

#include "stdafx.h"

#include <iostream>
#include <vector>
#include <stdlib.h>

#include "LogicSimplifier.h"
#include "gate.h"

const int MIN_INPUTS = 2;
const int MAX_INPUTS = 8;

void printBinary(int n, int len) {
	for (int i = len - 1; i >= 0; i--) {
		std::cout << ((n >> i) & 1);
	}
}

b_vec constructMapping(int nInputs, int nPerms) {
	b_vec ioMap(nPerms);
	std::cout << "Please enter 1 or 0 for each input combination.\n";

	for (int i = 0; i < nPerms; i++) {

		printBinary(i, nInputs);
		std::cout << " = ";

		int userInput;
		while (true) {
			std::cin >> userInput;
			if (userInput != 0 & userInput != 1) {
				std::cout << "Please enter 1 or 0.\n";
				printBinary(i, nInputs);
				std::cout << " = ";
			}
			else break;
		}
		ioMap[i] = userInput;
	}	
	return ioMap;
}

int main()
{
	//LogicGate gate1(LogicGate::AND, NULL, NULL);
	//std::cout << gate1.gateType << "\n";

	std::cout << "Please enter how many inputs there are (from " << MIN_INPUTS << " to " << MAX_INPUTS << "): ";

	int nInputs;

	while (true) {
		std::cin >> nInputs;
		if (nInputs < MIN_INPUTS || nInputs > MAX_INPUTS) {
			std::cout << "You entered a number outside of the range.\n";
		}
		else break;
	}

	int nInputPerms = 1 << nInputs;

	std::cout << "InputPerms: " << nInputPerms << "\n";

	b_vec ioMap = constructMapping(nInputs, nInputPerms);


	system("cls");

	std::cout << "Input/Output Mapping:\n";

	for (int i = 0; i < ioMap.size(); i++) {
		printBinary(i, nInputs);
		std::cout << " : " << ioMap[i] << "\n";
	}

    return 0;
}
