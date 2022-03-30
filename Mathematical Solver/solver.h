#ifndef  SOLVER_H
#define SOLVER_H

#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool is_valid(string ex);
bool char_in_string(char c, string s);
string format(string ex);
bool is_digit(char c);
float solve(string ex);

#endif //  SOLVER_H
