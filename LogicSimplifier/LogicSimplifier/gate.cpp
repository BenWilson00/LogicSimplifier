#include "stdafx.h"
#include "gate.h"

LogicGate::LogicGate(GType a, LogicGate ** b, LogicGate * c)
{
	gateType = a;
	memcpy(inputs[0], b[0], sizeof(b));
	output = c;
}

HighNode::HighNode(int inputStates) {

	baseInputStates = inputStates;

};