#ifndef GATE_H
#define GATE_H

class LogicGate {

public:
	enum GType { AND, OR, NOT, NAND, NOR, XOR, XNOR };
	LogicGate(GType, LogicGate **, LogicGate *);

private:
	LogicGate ** inputs;
	LogicGate * output;
	GType gateType;

};

class HighNode {

	LogicGate * input;

public:

	int baseInputStates;
	HighNode(int);

};

#endif