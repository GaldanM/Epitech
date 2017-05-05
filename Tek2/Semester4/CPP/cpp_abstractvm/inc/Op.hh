#ifndef OP_HH_
# define OP_HH_

# include			"IOperand.hh"

template <typename X>
class Op : public IOperand
{
protected:
  std::string			_str;
  eOperandType			_type;
  int				_precision;
  X				_nb;

public:
  Op(const eOperandType &type, const std::string &value);
  Op(const Op<X> &cpy);
  virtual			~Op();
  Op<X>&			operator=(const Op<X> &cpy);

  virtual std::string const&	toString() const;
  virtual int 			getPrecision() const;
  virtual eOperandType		getType() const;
  virtual X			getNb() const;

  virtual IOperand		*operator+(const IOperand &rhs) const;
  virtual IOperand		*operator-(const IOperand &rhs) const;
  virtual IOperand		*operator*(const IOperand &rhs) const;
  virtual IOperand		*operator/(const IOperand &rhs) const;
  virtual IOperand		*operator%(const IOperand &rhs) const;
};

#endif /* !OP_HH_ */
