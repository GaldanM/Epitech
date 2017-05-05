#ifndef CMD_HH
# define CMD_HH

# include	<iostream>

class Cmd
{
protected:
  std::string	_instr;
  std::string	_valor;
  std::string	_param;
  int 		_err;
  int 		_line;

public:
  Cmd(int);
  Cmd(const Cmd&);
  ~Cmd();
  Cmd&		operator=(const Cmd&);

  std::string	getInstr() const;
  std::string	getValor() const;
  std::string	getParam() const;
  int 		getErr() const;
  int 		getLine() const;

  int 		setInstr(int&, const std::string&);
  int 		setValor(int&, const std::string&);
  int 		setParam(int&, const std::string&);
  void		setErr(const int&);

  bool		checkInstr() const;
  bool		checkValor() const;
  bool		checkParam();
};

#endif /* !CMD_HH */
