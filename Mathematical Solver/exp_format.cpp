#include "solver.h"

string format(string ex)
{
	string new_ex = "";
	int i = -1;
	while (ex[++i])
		if ((ex[i] >= '0' && ex[i] <= '9') || char_in_string(ex[i], "+-*/.()^"))
			new_ex.append(1, ex[i]);
	return new_ex;
}