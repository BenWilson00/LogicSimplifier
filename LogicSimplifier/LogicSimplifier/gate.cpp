#include "stdafx.h"
#include "gate.h"

LogicGate::LogicGate(GType a, LogicGate * b [2], LogicGate * c)
{
	gateType = a;
	memcpy(prev[0], b[0], sizeof(b));
	next = c;
}
