#include "UIForm.h"
#include <iostream>

using namespace System;
using namespace System::Windows::Forms;

void printBinary(int n, int len) {
	for (int mask1 = (1 << len - 1); mask1 >= 1; mask1 >>= 1) {
		if (n & mask1) { std::cout << "1"; }
		else { std::cout << "0"; }
	}
	std::cout << std::endl;
}

template<typename T> int get_pos(std::vector<T> vec, T item) {
	int resultPos = std::find(vec.begin(), vec.end(), item) - vec.begin();
	if (resultPos < vec.size()) {
		return resultPos;
	}
	else {
		return -1;
	}
}

std::vector< std::vector<char> > getLogic(std::vector<char> outputSet, int nInputs, char lookUp) {

	int pos = get_pos(outputSet, lookUp);
	std::vector< std::vector<int> > groupSet;
	while (pos != -1) {

		std::vector<int> checkAgainst(1, pos);

		//see if there is an output change under different input
		//changes, and store groups of invariables
		for (int mask = (1 << (nInputs - 1)); mask >= 1; mask >>= 1) {

			bool change = false;

			//change "mask" bit
			std::vector<int> modified(checkAgainst);
			for (int i = 0; i < modified.size(); ++i) {
				modified[i] ^= mask;;

				//check for output change
				if ((outputSet[modified[i]] != lookUp) && outputSet[modified[i]] != '*') {
					change = true;
				}
			}

			//If there is no change, add to check list in order to look for larger groups
			if (!change) {
				checkAgainst.insert(checkAgainst.end(), modified.begin(), modified.end());
			}
		}
		for (int i = 0; i < checkAgainst.size(); ++i) {

			outputSet[checkAgainst[i]] = '*';
		}
		groupSet.push_back(checkAgainst);

		pos = get_pos(outputSet, lookUp);
	}

	//search for and remove redundant groups
	bool thisElementRedundant;
	bool allElementsRedundant;
	std::vector<int> redundantElements;


	for (int i = 0; i != groupSet.size(); ++i) {
		allElementsRedundant = true;

		//check this group's members for other references
		for (int e = 0; e != groupSet[i].size(); ++e) {
			thisElementRedundant = false;

			for (int j = 0; j != groupSet.size(); ++j) {
				if (i == j) { continue; }

				//match has been found for one group member
				if (get_pos(groupSet[j], groupSet[i][e]) != -1) {
					thisElementRedundant = true;
				}
			}
			//group is unique, abort
			if (!thisElementRedundant) {
				allElementsRedundant = false;
				break;
			}
		}
		//group is redundant - store for deletion
		if (allElementsRedundant) {
			redundantElements.push_back(i);
		}
	}

	//delete redundant elements
	for (int i = redundantElements.size() - 1; i >= 0; --i) {
		groupSet.erase(groupSet.begin() + redundantElements[i]);
	}

	//from final groups, find invariants
	std::vector< std::vector<char> > returnVector(groupSet.size());
	for (int i = 0; i != groupSet.size(); ++i) {
		int current;

		for (int mask = (1 << (nInputs - 1)); mask >= 1; mask >>= 1) {

			int change = false;
			current = groupSet[i][0] & mask;

			for (int j = 1; j != groupSet[i].size(); ++j) {

				//This variable has changed - not an invariant
				if (current ^ (groupSet[i][j] & mask)) {

					change = true;
					break;
				}
			}
			if (!change) {
				if (current == mask) { returnVector[i].push_back('1'); }
				else { returnVector[i].push_back('0'); }
			}
			else { returnVector[i].push_back('*'); }
		}
	}
	return returnVector;
}

[STAThread]
int main(array<String^>^ argv)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	LogicSimplifierUI::UIForm form;
	Application::Run(%form);

	return(0);
}

