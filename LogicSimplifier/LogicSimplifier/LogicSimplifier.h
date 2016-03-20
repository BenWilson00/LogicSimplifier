#ifndef LOGIC_SIMPLIFIER_H
#define LOGIC_SIMPLIFIER_H

typedef std::vector<bool> b_vec;

b_vec constructMapping(int, int);

void printBinary(int, int);
void printIOtable(b_vec, int);

#endif