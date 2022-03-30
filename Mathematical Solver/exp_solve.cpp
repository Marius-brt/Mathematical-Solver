#include "solver.h"

int precedence(char op) {
	if (op == '+' || op == '-')
		return 1;
	if (op == '*' || op == '/' || op == '^')
		return 2;
	return 0;
}

float calculate(float a, float b, char op) {
	switch (op) {
		case '+': return a + b;
		case '-': return a - b;
		case '*': return a * b;
		case '/': return a / b;
		case '^': return pow(a, b);
	}
}

float solve(string ex)
{
	stack<float> values;
	stack<char> ops;
	int i = -1;
	while (ex[++i])
	{
		if (ex[i] == '(')
			ops.push(ex[i]);
		else if (is_digit(ex[i]) || (ex[i] == '-' && (i == 0 || ex[i-1] == '(')))
		{
			string val;
			if (ex[i] == '-')
			{
				val += '-';
				i++;
			}
			while (i < ex.length() && (ex[i] == '.' || is_digit(ex[i])))
			{
				val += ex[i];
				i++;
			}
			values.push(stof(val));
			i--;
		}
		else if (ex[i] == ')')
		{
			while (!ops.empty() && ops.top() != '(')
			{
				float val2 = values.top();
				values.pop();
				float val1 = values.top();
				values.pop();
				char op = ops.top();
				ops.pop();
				values.push(calculate(val1, val2, op));
;			}
			if (!ops.empty())
				ops.pop();
		}
		else
		{
			while (!ops.empty() && precedence(ops.top())
				>= precedence(ex[i])) {
				float val2 = values.top();
				values.pop();
				float val1 = values.top();
				values.pop();
				char op = ops.top();
				ops.pop();
				values.push(calculate(val1, val2, op));
			}
			ops.push(ex[i]);
		}
	}
	while (!ops.empty()) {
		float val2 = values.top();
		values.pop();
		float val1 = values.top();
		values.pop();
		char op = ops.top();
		ops.pop();
		values.push(calculate(val1, val2, op));
	}
	return values.top();
}