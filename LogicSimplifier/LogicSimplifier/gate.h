#ifndef GATE_H
#define GATE_H

class LogicGate {

public:

	enum GType { AND, OR, NOT, NAND, NOR, XOR, XNOR };

	LogicGate(GType);

	void setInputs(LogicGate ** &inputList); 
	void setInputs(LogicGate * inputa, LogicGate * inputb = NULL);
	//void setOutput(LogicGate * out);
	void getInputAddr(std::vector<LogicGate *>  &addresses, int &index);
	LogicGate ** getInputs();


private:
	GType gateType;
	//LogicGate * output;
	LogicGate * inputs[2] = { NULL };

};

#endif