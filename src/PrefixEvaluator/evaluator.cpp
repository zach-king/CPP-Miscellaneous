#include <iostream>
#include <string>
#include <stack>
#include <cstring>

using namespace std;

int precedence(char tok)
{
	if (tok == '+')
	{
		return 1;
	}

	else if (tok == '-')
	{
		return 1;
	}

	else if (tok == '*')
	{
		return 2;
	}

	else if (tok == '/')
	{
		return 2;
	}
}


bool isNumber(char token)
{
	return !(token == '+' || token == '-' || token == '*' || token == '/');
}

bool isOperator(char token)
{
	return !isNumber(token);
}

int exp(string input)
{
	const char *tokens = input.c_str();
	stack <int>num;
	stack <char> sym;
	int o1 = 0;
	int o2 = 0;
	int result;



	for (int i = 0; i < input.length(); i++)
	{
		char token = tokens[i];
		if (token == ' ')
			continue;

		if (isNumber(token))
		{
			num.push(token - '0'); // - '0' converts char to int
		}
		else if (isOperator(token) && sym.empty())
		{
			sym.push(token);
		}
		else if (isOperator(token) && !sym.empty() && precedence(token) > precedence(sym.top()))
		{
			sym.push(token);
		}

		while (!sym.empty() && !num.empty()) {
			o2 = num.top();
			num.pop();
			o1 = num.top();
			num.pop();

			char opertr = sym.top();
			sym.pop();

			if (opertr == '+')
			{
				result = o1 + o2;
				num.push(result);
			}
			else if (opertr == '-')
			{
				result = o1 - o2;
				num.push(result);
			}
			else if (opertr == '*')
			{
				result = o1*o2;
				num.push(result);
			}
			else if (opertr == '/')
			{
				result = o1 / o2;
				num.push(result);
			}
		}
	}

	return(num.top());
}


int main()
{
	string input;

	cout << "Please enter an arithmetic expression" << endl;
	getline(cin, input);

	int answer;
	answer = exp(input);

	cout << "Answer to this expression" << endl;
	cout << answer << endl;

    return 0;
}