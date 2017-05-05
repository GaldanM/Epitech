#ifndef  CALCULATOR_HH_
# define CALCULATOR_HH_

# include	<list>
# include	"Cmd.hh"
# include	"Op.hh"

class Calculator
{
private:
  std::list<IOperand*>	_list;

private:
  IOperand*	(Calculator::*_foncPtr[5])(const std::string&);
  IOperand*	createInt8(const std::string&);
  IOperand*	createInt16(const std::string&);
  IOperand*	createInt32(const std::string&);
  IOperand*	createFloat(const std::string&);
  IOperand*	createDouble(const std::string&);

public:
  Calculator();
  Calculator(const Calculator&);
  ~Calculator();
  Calculator&	operator=(const Calculator&);

public:
  IOperand*	createOperand(const eOperandType&, const std::string&);

public:
  bool		exec_cmd(std::list<Cmd *>&);
  eOperandType	choose_type(const std::string&);
  void		check_flow(const std::string&, const std::string&, const int&);

  void		push(const Cmd *);
  void		assert(const Cmd *);
  void		pop(const Cmd *);
  void		dump();
  void		add(const Cmd *);
  void		sub(const Cmd *);
  void		mul(const Cmd *);
  void		div(const Cmd *);
  void		mod(const Cmd *);
  void		print(const Cmd *);
};

#endif /* !CALCULATOR_HH_ */
