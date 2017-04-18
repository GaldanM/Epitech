#include "Parser.h"
#include <cstdlib>

#define OPE(c) (c == '+' || c == '-' || c == '*' || c == '/' || c == '%')

Parser::Parser() : _result(0)
{

}

Parser::Parser(Parser const &cpy)
{
	_result = cpy._result;
	_operators = cpy._operators;
	_numbers = cpy._numbers;
	_calculs = cpy._calculs;
	_tmp = cpy._tmp;
}

Parser::~Parser()
{
	
}

Parser&		Parser::operator=(Parser const &cpy)	
{
	if (&cpy && &cpy != this)
	{
		_result = cpy._result;
		_operators = cpy._operators;
		_numbers = cpy._numbers;
		_calculs = cpy._calculs;
		_tmp = cpy._tmp;
	}
	return (*this);
}

void	Parser::fill_stack(std::string const &expr)
{
	int i = 0;
	std::string token;

	while (expr[i])
	{
		 token.clear();
		 if (expr[i] == '(' || OPE(expr[i]))
		 {
		 	token.push_back(expr[i]);
		 	_operators.push(token);
		 }
		 else if (expr[i] >= '0' && expr[i] <= '9')
		 {
		 	while (expr[i] && expr[i] >= '0' && expr[i] <= '9')
		 	{
		 		token.push_back(expr[i]);
		 		++i;
		 	}
		 	_numbers.push(token);
		 	--i;
		 }
		 else if (!expr[i] || expr[i] == ')')
		 {
		 	while (!_operators.empty() && _operators.top() != "(")
		 	{
		 		_numbers.push(_operators.top());
		 		_operators.pop();
		 	}
		 	_operators.pop();
		 }
		 ++i;
	}
	while (!_operators.empty())
	{
		_numbers.push(_operators.top());
		_operators.pop();
	}
}

void	Parser::invert_stack()
{
	while (!_numbers.empty())
	{
		_tmp.push(_numbers.top());
		_numbers.pop();
	}
}

void	Parser::exec_calcs()
{
	int 	a;
	int 	b;
	int 	total;

	while (!_tmp.empty())
	{
		while (!OPE(_tmp.top()[0]))
		{
			_numbers.push(_tmp.top());
			_tmp.pop();
		}
		if (!_numbers.empty())
		{
			std::istringstream nb(_numbers.top().c_str());
			nb >> b;
			_numbers.pop();
		}
		else
		{
			b = _calculs.top();
			_calculs.pop();
		}
		if (!_numbers.empty())
		{
			std::istringstream nb(_numbers.top().c_str());
			nb >> a;
			_numbers.pop();
		}
		else
		{
			a = _calculs.top();
			_calculs.pop();
		}
		if (_tmp.top() == "+")
		{
			total = a + b;
			_calculs.push(total);
		}

		else if (_tmp.top() == "-")
		{
			total = a - b;
			_calculs.push(total);
		}

		else if (_tmp.top() == "*")
		{
			total = a * b;
			_calculs.push(total);
		}

		else if (_tmp.top() == "/")
		{
			total = a / b;
			_calculs.push(total);
		}

		else if (_tmp.top() == "%")
		{
			total = a % b;
			_calculs.push(total);
		}
		_tmp.pop();
	}
_result += total;
}

void	Parser::feed(std::string const &expr)
{
	fill_stack(expr);
	invert_stack();
	exec_calcs();	
}

void	Parser::reset()
{
	_result = 0;
	while (!_operators.empty())
		_operators.pop();
	while (!_numbers.empty())
		_numbers.pop();
	while (!_tmp.empty())
		_tmp.pop();
	while (!_calculs.empty())
		_calculs.pop();
}

int	Parser::result() const
{
	return _result;
}
