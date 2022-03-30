#include "solver.h"

int main()
{
	string exp ;
	while (1)
	{
		cout << "Enter mathematical expression : ";
		getline(cin, exp);
		exp = format(exp);
		if (!is_valid(exp))
			cout << "Invalid !" << endl;
		else
			cout << exp << " = " << solve(exp) << endl;
	}
	return 0;
}