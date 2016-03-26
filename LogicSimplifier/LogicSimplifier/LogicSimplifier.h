#ifndef LOGIC_SIMPLIFIER_H
#define LOGIC_SIMPLIFIER_H

#define LEN(arr) (sizeof(arr)/sizeof(arr[0]))

typedef std::vector<bool> b_vec;

b_vec constructMapping(int, int);

void printBinary(int, int);
void printIOtable(b_vec, int);

#endif