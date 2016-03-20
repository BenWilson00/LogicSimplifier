#include "stdafx.h"
#include "gate.h"

LogicGate::LogicGate(GType a, LogicGate * b, LogicGate * c)
{
	gateType = a;
	prev = b;
	next = c;
}
