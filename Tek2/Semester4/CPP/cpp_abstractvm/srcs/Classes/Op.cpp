#include		<cstdint>
#include		<sstream>
#include		"MyError.hh"
#include		"Calculator.hh"
#include		"Op.hh"

template <typename X>
Op<X>::Op(const eOperandType &type, const std::string & value) : _type(type), _precision(type)
{
  std::ostringstream	result;
  std::istringstream	n(value);
  double		conv;

  n >> conv;
  _nb = static_cast<X>(conv);
  if (type != Int8)
    result << _nb;
  else
    result << static_cast<int>(_nb);
  _str = result.str();
}

template <typename X>
Op<X>::Op(const Op<X> &cpy)
{
  if (&cpy)
    {
      _str = cpy._str;
      _type = cpy._type;
      _precision = cpy._precision;
      _nb = cpy._nb;
    }
}

template <typename X>
Op<X>::~Op()
{

}

template		<typename X>
Op<X>&			Op<X>::operator=(const Op<X> &cpy)
{
  if (&cpy)
    {
      _str = cpy._str;
      _type = cpy._type;
      _precision = cpy._precision;
      _nb = cpy._nb;
    }
  return (*this);
}

template		<typename X>
std::string const&	Op<X>::toString() const
{
  return _str;
}

template		<typename X>
int 			Op<X>::getPrecision() const
{
  return _precision;
}

template		<typename X>
eOperandType		Op<X>::getType() const
{
  return _type;
}

template		<typename X>
X			Op<X>::getNb() const
{
  return _nb;
}

template		<typename X>
IOperand		*Op<X>::operator+(const IOperand &rhs) const
{
  double 		conv;
  IOperand		*ret = NULL;
  Calculator		calc;
  eOperandType		bigType;
  std::istringstream	n(rhs.toString());
  std::ostringstream	result;

  if (_type >= rhs.getType())
    bigType = _type;
  else
    bigType = rhs.getType();
  n >> conv;
  conv += _nb;
  result << conv;
  ret = calc.createOperand(bigType, result.str());
  return ret;
}

template		<typename X>
IOperand		*Op<X>::operator-(const IOperand &rhs) const
{
  double 		conv;
  IOperand		*ret = NULL;
  Calculator		calc;
  eOperandType		bigType;
  std::istringstream	n(rhs.toString());
  std::ostringstream	result;

  if (_type >= rhs.getType())
    bigType = _type;
  else
    bigType = rhs.getType();
  n >> conv;
  conv = _nb - conv;
  result << conv;
  ret = calc.createOperand(bigType, result.str());
  return ret;
}

template		<typename X>
IOperand		*Op<X>::operator*(const IOperand &rhs) const
{
  double 		conv;
  IOperand		*ret = NULL;
  Calculator		calc;
  eOperandType		bigType;
  std::istringstream	n(rhs.toString());
  std::ostringstream	result;

  if (_type >= rhs.getType())
    bigType = _type;
  else
    bigType = rhs.getType();
  n >> conv;
  conv = conv * _nb;
  result << conv;
  ret = calc.createOperand(bigType, result.str());
  return ret;
}

template		<typename X>
IOperand		*Op<X>::operator/(const IOperand &rhs) const
{
  double 		conv;
  IOperand		*ret = NULL;
  Calculator		calc;
  eOperandType		bigType;
  std::istringstream	n(rhs.toString());
  std::ostringstream	result;

  if (_type >= rhs.getType())
    bigType = _type;
  else
    bigType = rhs.getType();
  n >> conv;
  if (conv != 0)
    conv = _nb / conv;
  else
    throw MyError("Div by 0 impossible !\n");
  result << conv;
  ret = calc.createOperand(bigType, result.str());
  return ret;
}

template		<typename X>
IOperand		*Op<X>::operator%(const IOperand &rhs) const
{
  double 		conv;
  IOperand		*ret = NULL;
  Calculator		calc;
  eOperandType		bigType;
  std::istringstream	n(rhs.toString());
  std::ostringstream	result;

  if (_type >= rhs.getType())
    bigType = _type;
  else
    bigType = rhs.getType();
  n >> conv;
  if (conv != 0)
    conv = static_cast<int>(_nb) % static_cast<int>(conv);
  else
    throw MyError("Mod by 0 impossible !\n");
  result << conv;
  ret = calc.createOperand(bigType, result.str());
  return ret;
}

template		Op<int8_t>::Op(const eOperandType &type, const std::string & value);
template		Op<int16_t>::Op(const eOperandType &type, const std::string & value);
template		Op<int32_t>::Op(const eOperandType &type, const std::string & value);
template		Op<float>::Op(const eOperandType &type, const std::string & value);
template		Op<double>::Op(const eOperandType &type, const std::string & value);
