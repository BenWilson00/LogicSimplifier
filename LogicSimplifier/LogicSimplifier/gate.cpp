#include "stdafx.h"

#include <vector>
#include <iostream>

#include "LogicSimplifier.h"
#include "gate.h"

void LogicGate::setInputs(LogicGate ** &inputList) {
	memcpy(inputs[0], inputList[0], sizeof(inputList));
};

void LogicGate::setInputs(LogicGate * inputa, LogicGate * inputb) {
	inputs[0] = inputa;
	inputs[1] = inputb;
}

LogicGate ** LogicGate::getInputs() {
	return inputs;
}

void LogicGate::getInputAddr(std::vector<LogicGate *> &addresses, int &index) {
	std::cout << "\nLEN(addresses) = " << addresses.size();
	std::cout << "\naddresses = ";
	for (int i = 0; i < addresses.size(); ++i) { std::cout << addresses[i] << ", "; }
	std::cout << "\nindex = " << index << "\na";
	std::cout << "\nLEN(inputs) = " << LEN(inputs);
	for (int i = 0; i < LEN(inputs); ++i) {

		std::cout << "\nb";

		if ((i < 1) | (gateType != NOT)) {

			std::cout << "\nc";

			if (inputs[i] == NULL) {
				addresses[index] = inputs[i];
				return;
			}
			else {
				++index;
				(*inputs[i]).getInputAddr(addresses, index);
			}
		}
	}
};

LogicGate::LogicGate(LogicGate::GType a)
{
	gateType = a;
};