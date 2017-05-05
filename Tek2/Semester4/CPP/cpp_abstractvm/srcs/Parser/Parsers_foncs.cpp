#include			<sstream>
#include			"MyError.hh"
#include			"Parser.hh"

std::string			epur_str(const std::string &line)
{
  int				i = 0;
  std::string			epur = "";

  while (line[i] && (line[i] == ' ' || line[i] == '\t'))
    i++;
  while (line[i])
    {
      while(line[i] && line[i] != ' ' && line[i] != '\t')
	{
	  if (line[i] == ';')
	    return (epur);
	  epur.push_back(line[i]);
	  i++;
	}
      while (line[i] && (line[i] == ' ' || line[i] == '\t'))
	i++;
      if (line[i] && line[i] != '\n' && line[i] != ';')
	epur.push_back(' ');
    }
  return (epur);
}

bool				check_cmd(Cmd *cmd)
{
  if ((cmd->getInstr() == "push" || cmd->getInstr() == "assert") && (cmd->getValor().empty() || cmd->getParam().empty()))
    {
      cmd->setErr(8);
      return (false);
    }
  if (cmd->getInstr() != "push" && cmd->getInstr() != "assert" && !cmd->getValor().empty() && !cmd->getParam().empty())
    {
      cmd->setErr(9);
      return (false);
    }
  return (true);
}

bool				fill_cmd(const std::string &line, Cmd *cmd)
{
  int				i = 0;

  cmd->setInstr(i, line);
  if (cmd->checkInstr())
    {
      if (cmd->setValor(i, line) == -1)
	return (false);
      if (cmd->checkValor() && !cmd->getValor().empty())
	{
	  if (cmd->setParam(i, line) == -1)
	    return (false);
	  if (!cmd->checkParam())
	    return (false);
	}
      else if (!cmd->getValor().empty())
	{
	  cmd->setErr(10);
	  return (false);
	}
    }
  else
    {
      cmd->setErr(11);
      return (false);
    }
  return (true);
}

void				display_error(const std::list<Cmd *>::iterator &it)
{
  int				error;
  std::ostringstream		s;
  std::string			message;
  std::string			errors[15] =
    {
      "Value is incorrect, must be this form :\n\"INSTR\" \"VALUE\"(\"PARAM\")",
      "Only alphanumerics numbers and \".\" or \"-\" are accepted !",
      "Only one negative sign is accepted !",
      "\"-\" can only be at the beginning !",
      "\"" + (*it)->getValor() + "\" can't accept decimal numbers !",
      "Only one decimal mark is accepted !",
      "Decimal mark can't be at the beginning or at the end !",
      "\"" + (*it)->getInstr() + "\" need a value !",
      "\"" + (*it)->getInstr() + "\" can't have a value !",
      "\"" + (*it)->getValor() + "\" is not a value !",
      "\"" + (*it)->getInstr() + "\" is not an instruction !",
      "Unexpected token at the end of the line !",
      "\"" + (*it)->getValor() + "\" must have decimal number !"
    };

  s << "Error at line " << (*it)->getLine() << " : ";
  message = s.str();
  error = (*it)->getErr();
  if (error != 0)
    {
      throw MyError(message + errors[error - 1] + "\n");
    }
}

bool				check_errors(std::list<Cmd *> &list)
{
  bool				quit = false;
  std::list<Cmd *>::iterator	it = list.begin();

  while (it != list.end())
    {
      if ((*it)->getInstr() == "exit")
	quit = true;
      ++it;
    }
  if (!quit)
    throw MyError("Instruction \"exit\" is missing !");
  it = list.begin();
  while (it != list.end())
    {
      display_error(it);
      ++it;
    }
  return (true);
}
