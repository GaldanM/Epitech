#ifndef PARSER_H_
# define PARSER_H_

#include <iostream>
#include <stack>
#include <sstream>
#include <string>

class Parser
{
private:
	std::stack<std::string> _operators;
	std::stack<std::string> _numbers;
	std::stack<std::string> _tmp;
	std::stack<int> 		_calculs;
	int						_result;

public:
	Parser();
	Parser(Parser const&);
	~Parser();
	Parser& operator=(Parser const&);

	int			result() const;
	void		fill_stack(std::string const&);
	void		invert_stack();
	void		exec_calcs();
	void		feed(std::string const&);
	void		reset();
};

#endif