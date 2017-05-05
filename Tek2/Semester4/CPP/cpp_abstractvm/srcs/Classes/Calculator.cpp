#include		<cstdint>
#include		<iterator>
#include		<sstream>
#include		<limits>
#include		"MyError.hh"
#include		"Calculator.hh"

Calculator::Calculator()
{
  _foncPtr[Int8] = &Calculator::createInt8;
  _foncPtr[Int16] = &Calculator::createInt16;
  _foncPtr[Int32] = &Calculator::createInt32;
  _foncPtr[Float] = &Calculator::createFloat;
  _foncPtr[Double] = &Calculator::createDouble;
}

Calculator::Calculator(const Calculator &cpy)
{
  if (&cpy)
    {
      _list = cpy._list;
    }
}

Calculator::~Calculator()
{

}

Calculator		&Calculator::operator=(const Calculator &cpy)
{
  if (&cpy)
    {
      _list = cpy._list;
    }
  return (*this);
}

IOperand		*Calculator::createOperand(const eOperandType &type, const std::string & value)
{
  IOperand		*ret = NULL;

  ret = (this->*_foncPtr[type])(value);
  return ret;
}

IOperand		*Calculator::createInt8(const std::string & value)
{
  return (new Op<int8_t>(Int8, value));
}

IOperand		*Calculator::createInt16(const std::string & value)
{
  return (new Op<int16_t>(Int16, value));
}

IOperand		*Calculator::createInt32(const std::string & value)
{
  return (new Op<int32_t>(Int32, value));
}

IOperand		*Calculator::createFloat(const std::string & value)
{
  return (new Op<float>(Float, value));
}

IOperand		*Calculator::createDouble(const std::string & value)
{
  return (new Op<double>(Double, value));
}

bool			Calculator::exec_cmd(std::list<Cmd *> & cmd_list)
{
  std::list<Cmd *>::iterator	it;
  std::string 			instr;

  for (it = cmd_list.begin(); it != cmd_list.end(); ++it)
    {
      instr = (*it)->getInstr();
      if (instr == "push")
	push(*it);
      else if (instr == "pop")
	pop(*it);
      else if (instr == "dump")
	dump();
      else if (instr == "assert")
	assert(*it);
      else if (instr == "add")
	add(*it);
      else if (instr == "sub")
	sub(*it);
      else if (instr == "mul")
	mul(*it);
      else if (instr == "div")
	div(*it);
      else if (instr == "mod")
	mod(*it);
      else if (instr == "print")
	print(*it);
      else if (instr == "exit")
	return false;
    }
  return true;
}

eOperandType		Calculator::choose_type(const std::string & type)
{
  if (type == "int8")
    return Int8;
  else if (type == "int16")
    return Int16;
  else if (type == "int32")
    return Int32;
  else if (type == "float")
    return Float;
  return Double;
}

void			Calculator::check_flow(const std::string &type, const std::string &param, const int &line)
{
  std::istringstream	nb(param);
  std::ostringstream 	s;
  long double		conv;
  std::string 		msg;

  s << "Error at line " << line << " : ";
  msg = s.str();
  nb >> conv;
  if (type == "int8")
    {
      if (conv > std::numeric_limits<int8_t>::max() ||
	  conv < std::numeric_limits<int8_t>::min())
	throw MyError(msg + "\"Int8\" underflow/overflow !\n");
    }
  else if (type == "int16")
    {
      if (conv > std::numeric_limits<int16_t>::max() ||
	  conv < std::numeric_limits<int16_t>::min())
	throw MyError(msg + "\"Int16\" underflow/overflow !\n");
    }
  else if (type == "int32")
    {
      if (conv > std::numeric_limits<int32_t>::max() ||
	  conv < std::numeric_limits<int32_t>::min())
	throw MyError(msg + "\"Int32\" underflow/overflow !\n");
    }
  else if (type == "float")
    {
      if (conv > std::numeric_limits<float>::max() ||
	  conv < std::numeric_limits<float>::min())
	throw MyError(msg + "\"Float\" underflow/overflow !\n");
    }
  else if (type == "double")
    {
      if (conv > std::numeric_limits<double>::max() ||
	  conv < std::numeric_limits<double>::min())
	throw MyError(msg + "\"Double\" underflow/overflow !\n");
    }
}

void			Calculator::push(const Cmd * obj)
{
  IOperand		*elem = NULL;
  eOperandType		type = choose_type(obj->getValor());

  check_flow(obj->getValor(), obj->getParam(), obj->getLine());
  elem = createOperand(type, obj->getParam());
  _list.push_back(elem);
}

void			Calculator::assert(const Cmd * obj)
{
  std::ostringstream	s;
  std::string 		msg;
  IOperand		*end = _list.back();

  s << "Error at line " << obj->getLine() << " : ";
  msg = s.str();
  check_flow(obj->getValor(), obj->getParam(), obj->getLine());
  if (_list.empty())
    throw MyError(msg + "Assert on empty stack\n");
  else
    {
      if (end->getType() != choose_type(obj->getValor()) ||
	  end->toString() != obj->getParam())
	throw MyError(msg + "Assert: Difference !\n");
    }
}

void			Calculator::pop(const Cmd * obj)
{
  std::ostringstream	s;
  std::string		msg;

  s << "Error at line " << obj->getLine();
  msg = s.str();
  if (_list.empty())
    throw MyError(msg + " : Pop on empty stack\n");
  else
    _list.pop_back();
}

void			Calculator::dump()
{
  std::list<IOperand *>::reverse_iterator it;

  for (it = _list.rbegin(); it != _list.rend(); ++it)
    {
      std::cout << (*it)->toString() << std::endl;
    }
}

void			Calculator::add(const Cmd * obj)
{
  std::ostringstream	s;
  std::string		msg;
  IOperand		*end1;
  IOperand		*end2;
  IOperand		*res;
  std::list<IOperand *>::reverse_iterator	it;

  s << "Error at line " << obj->getLine();
  msg = s.str();
  if (_list.size() < 2)
    throw MyError(msg + " : Add need 2 elems\n");
  else
    {
      it = _list.rbegin();
      end1 = *it;
      ++it;
      end2 = *it;
      res = *end1 + *end2;

      _list.pop_back();
      _list.pop_back();
      _list.push_back(res);
    }
}

void			Calculator::sub(const Cmd * obj)
{
  std::ostringstream	s;
  std::string		msg;
  IOperand		*end1;
  IOperand		*end2;
  IOperand		*res;
  std::list<IOperand *>::reverse_iterator it;

  s << "Error at line " << obj->getLine();
  msg = s.str();
  if (_list.size() < 2)
    throw MyError(msg + " : Sub need 2 elems\n");
  else
    {
      it = _list.rbegin();
      end1 = *it;
      ++it;
      end2 = *it;
      res = *end1 - *end2;

      _list.pop_back();
      _list.pop_back();
      _list.push_back(res);
    }
}

void			Calculator::mul(const Cmd * obj)
{
  std::ostringstream	s;
  std::string		msg;
  IOperand		*end1;
  IOperand		*end2;
  IOperand		*res;
  std::list<IOperand *>::reverse_iterator it;

  s << "Error at line " << obj->getLine();
  msg = s.str();
  if (_list.size() < 2)
    throw MyError(msg + " : Mul need 2 elems\n");
  else
    {
      it = _list.rbegin();
      end1 = *it;
      ++it;
      end2 = *it;
      res = *end1 * *end2;

      _list.pop_back();
      _list.pop_back();
      _list.push_back(res);
    }
}

void			Calculator::div(const Cmd * obj)
{
  std::ostringstream	s;
  std::string		msg;
  IOperand		*end1;
  IOperand		*end2;
  IOperand		*res;
  std::list<IOperand *>::reverse_iterator it;

  s << "Error at line " << obj->getLine();
  msg = s.str();
  if (_list.size() < 2)
    throw MyError(msg + " : Div need 2 elems\n");
  else
    {
      it = _list.rbegin();
      end1 = *it;
      ++it;
      end2 = *it;
      res = *end1 / *end2;

      _list.pop_back();
      _list.pop_back();
      _list.push_back(res);
    }
}

void			Calculator::mod(const Cmd * obj)
{
  std::ostringstream	s;
  std::string		msg;
  IOperand		*end1;
  IOperand		*end2;
  IOperand		*res;
  std::list<IOperand *>::reverse_iterator it;

  s << "Error at line " << obj->getLine();
  msg = s.str();
  if (_list.size() < 2)
    throw MyError(msg + " : Mod need 2 elems\n");
  else
    {
      it = _list.rbegin();
      end1 = *it;
      ++it;
      end2 = *it;
      res = *end1 % *end2;

      _list.pop_back();
      _list.pop_back();
      _list.push_back(res);
    }
}

void			Calculator::print(const Cmd * obj)
{
  int 			nouv;
  std::ostringstream	s;
  std::string		msg;
  IOperand 		*end = _list.back();

  s << "Error at line " << obj->getLine();
  msg = s.str();
  if (_list.empty())
    throw MyError(msg + " : Print on empty stack\n");
  else
    {
      std::istringstream	n(end->toString());

      n >> nouv;
      if (end->getType() == Int8)
	std::cout << static_cast<char>(nouv) << std::endl;
    }
}
