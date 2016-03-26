// LogicSimplifier.cpp : does things
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>

#include "LogicSimplifier.h"
#include "gate.h"

const int MIN_INPUTS = 2;
const int MAX_INPUTS = 8;
std::string INPUT_NAMES = "ABCDEFGH";

// take the high outputs, and construct a logic system to create each
void generateSingleOutputs(b_vec ioMap, int nInputs) {

	std::vector<LogicGate> highOutputs;

	int mask;
	int hOCount = 0;
	for (int i = 0; i < ioMap.size(); ++i) {
		if (ioMap[i]) {
			highOutputs.push_back(LogicGate(LogicGate::AND));

			LogicGate * currGate = &highOutputs[hOCount];

			bool bInput;
			for (mask = 1 << nInputs-1; mask > 0; mask >>= 1) {
				bInput = ((mask & i) != 0);

				if (bInput == 0) {
					(*currGate).setInputs(&LogicGate(LogicGate::NOT), &LogicGate(LogicGate::AND));
					std::cout << "\nAND(NOT A, B)\n";
				}
				else {
					(*currGate).setInputs(NULL, &LogicGate(LogicGate::AND));
					std::cout << "\nAND(O, B)\n";
				}
				currGate = (*currGate).getInputs()[1];
			}
			++hOCount;
		}
	}
	std::vector< std::vector<LogicGate *> > inputPointersList (hOCount, std::vector<LogicGate *>(nInputs));
	int startIndex = 0;
	highOutputs[0].getInputAddr(inputPointersList[0], startIndex);
}

void printBinary(int n, int len) {
	for (int i = len - 1; i >= 0; i--) {
		std::cout << ((n >> i) & 1);
	}
}

void printIOtable(b_vec ioMap, int len) {
	for (int i = 0; i < len; ++i) {
		std::cout << INPUT_NAMES[i];
	}
	std::cout << " | Q\n";

	for (int i = 0; i < len; ++i) {
		std::cout << "-";
	}
	std::cout << "----\n";

	for (int i = 0; i < ioMap.size(); ++i) {
		printBinary(i, len);
		std::cout << " | " << ioMap[i] << "\n";
	}
}

b_vec constructMapping(int nInputs, int nPerms) {
	b_vec ioMap(nPerms);
	std::cout << "Please enter 1 or 0 for each input combination.\n";

	for (int i = 0; i < nPerms; ++i) {

		printBinary(i, nInputs);
		std::cout << " = ";

		bool userInput;
		std::cin >> userInput;

		while (std::cin.fail()) {
			std::cout << "Please enter 1 or 0.\n";
			printBinary(i, nInputs);
			std::cout << " = ";

			std::cin.clear();
			std::cin.ignore(256, '\n');
			std::cin >> userInput;
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
	std::cin >> nInputs;

	while (std::cin.fail() || nInputs < MIN_INPUTS || nInputs > MAX_INPUTS) {
		std::cout << "Please enter a number in the correct range.\n";

		std::cin.clear();
		std::cin.ignore(256, '\n');
		std::cin >> nInputs;
	}

	int nInputPerms = 1 << nInputs;

	std::cout << "InputPerms: " << nInputPerms << "\n";

	b_vec ioMap = constructMapping(nInputs, nInputPerms);

	system("cls");
	
	printIOtable(ioMap, nInputs);

	generateSingleOutputs(ioMap, nInputs);

    return 0;
}
