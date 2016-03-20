#ifndef GATE_H
#define GATE_H

class LogicGate {

  public:
    enum GType { AND, OR, NOT, NAND, NOR, XOR, XNOR };

	LogicGate * prev[2];
	LogicGate * next;
	GType gateType;

	LogicGate(GType, LogicGate * [2], LogicGate *);

};

#endif