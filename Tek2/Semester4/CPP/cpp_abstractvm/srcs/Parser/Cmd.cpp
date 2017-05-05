#include	"Cmd.hh"

Cmd::Cmd(int line) : _instr(""), _valor(""), _param(""), _err(0), _line(line)
{

}

Cmd::Cmd(const Cmd &cpy)
{
  if (&cpy)
    {
      _line = cpy._line;
      _err = cpy._err;
      _instr = cpy._instr;
      _valor = cpy._valor;
      _param = cpy._param;
    }
}

Cmd::~Cmd()
{

}

Cmd&		Cmd::operator=(const Cmd &cpy)
{
  if (&cpy)
    {
      _line = cpy._line;
      _err = cpy._err;
      _instr = cpy._instr;
      _valor = cpy._valor;
      _param = cpy._param;
    }
  return (*this);
}

std::string	Cmd::getInstr() const
{
  return _instr;
}

std::string	Cmd::getValor() const
{
  return _valor;
}

std::string	Cmd::getParam() const
{
  return _param;
}

int 		Cmd::getErr() const
{
  return _err;
}

int 		Cmd::getLine() const
{
  return _line;
}

int			Cmd::setInstr(int &i, const std::string &line)
{
  int 			beg = 0;
  int 			end = 0;

  while (line[i] && (line[i] == ' ' || line[i] == '\t'))
    i++;
  beg = i;
  while (line[i] && line[i] != ' ' && line[i] != '\t')
    i++;
  end = i;
  if (end != beg)
    {
      while (beg < end)
	{
	  _instr.push_back(line[beg]);
	  beg++;
	}
    }
  return (0);
}

int			Cmd::setValor(int &i, const std::string &line)
{
  int 			beg = 0;
  int 			end = 0;

  while (line[i] && (line[i] == ' ' || line[i] == '\t'))
    i++;
  beg = i;
  while (line[i] && line[i] != '(')
    i++;
  end = i;
  if (end != beg)
    {
      while (beg < end)
	{
	  _valor.push_back(line[beg]);
	  beg++;
	}
    }
  if (!line[i] && (_instr == "push" || _instr == "assert") && !_valor.empty())
    {
      _err = 1;
      return (-1);
    }
  return (0);
}

int			Cmd::setParam(int &i, const std::string &line)
{
  int 			beg = 0;
  int 			end = 0;

  while (line[i] && line[i] == '(')
    i++;
  beg = i;
  while (line[i] && line[i] != ')')
    i++;
  if (!line[i])
    {
      _err = 1;
      return (-1);
    }
  end = i;
  if (line.size() != (size_t)i + 1)
    _err = 12;
  if (end != beg)
    {
      while (beg < end)
	{
	  _param.push_back(line[beg]);
	  beg++;
	}
    }
  return (0);
}

void			Cmd::setErr(const int &code)
{
  _err = code;
}

bool			Cmd::checkInstr() const
{
  int			i = 0;
  std::string		tab[12] =
    {
      "push",
      "pop",
      "dump",
      "assert",
      "add",
      "sub",
      "mul",
      "div",
      "mod",
      "print",
      "exit",
      "end"
    };

  while (tab[i] != "end")
    {
      if (tab[i] == _instr)
	return (true);
      i++;
    }
  return (false);
}

bool			Cmd::checkValor() const
{
  int			i = 0;
  std::string		tab[6] =
    {
      "int8",
      "int16",
      "int32",
      "float",
      "double",
      "end"
    };
  if (_valor.empty())
    return (true);
  while (tab[i] != "end")
    {
      if (tab[i] == _valor)
	return (true);
      i++;
    }
  return (false);
}

bool			Cmd::checkParam()
{
  int			i = 0;
  char			pnt = 0;
  char			less = 0;

  while (_param[i])
    {
      if (!((_param[i] >= '0' && _param[i] <= '9') || _param[i] == '-' || _param[i] == '.'))
	_err = 2;
      else if(_param[i] == '-')
	{
	  if (!less)
	    less = 1;
	  else if (less)
	    _err = 3;
	  else if (i != 0)
	    _err = 4;
	}
      else if(_param[i] == '.')
	{
	  if (_valor != "double" && _valor != "float")
	    _err = 5;
	  else if (!pnt)
	    pnt = 1;
	  else if (pnt)
	    _err = 6;
	  else if (!i || (size_t)i + 1 == _param.size())
	    _err = 7;
	}
      if (_err != 0)
	return (false);
      i++;
    }
  if ((_valor == "double" || _valor == "float"))
    {
      if(!pnt)
	_err = 13;
      return (false);
    }
  return (true);
}
