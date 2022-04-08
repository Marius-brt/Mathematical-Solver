#include "solver.h"

bool is_digit(char c)
{
	return c >= '0' && c <= '9';
}

bool char_in_string(char c, string s)
{
	int i = -1;
	while (s[++i])
		if (s[i] == c)
			return true;
	return false;
}

int count_char(char c, string s)
{
	int i = -1;
	int count = 0;
	while (s[++i])
		if (s[i] == c)
			count++;
	return count;
}

bool is_valid(string ex)
{
	if (ex.length() == 0 || char_in_string(ex[0], "^+*/.") || char_in_string(ex[ex.length()-1], "-*/+.^"))
		return false;
	if (count_char('(', ex) != count_char(')', ex))
		return false;
	int opened = 0;
	int i = -1;
	bool was_op = false;
	while (ex[++i])
	{
		if (char_in_string(ex[i], "+-*/.^"))
		{
			if (was_op)
				return false;
			was_op = true;
		}
		else
			was_op = false;
		if (ex[i] == '(')
			opened++;
		if (ex[i] == ')')
		{
			if (opened <= 0)
				return false;
			opened--;
		}
	}
	if(opened > 0) return false;
	return true;
}
