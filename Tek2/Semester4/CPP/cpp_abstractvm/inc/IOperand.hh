#ifndef IOPERAND_HH_
# define IOPERAND_HH_

# include	<iostream>

typedef enum	eOperandType
  {
    Int8,
    Int16,
    Int32,
    Float,
    Double
  }		eOperandType;

class IOperand
{
public:

  virtual std::string const&	toString() const = 0;
  virtual int 			getPrecision() const = 0;
  virtual eOperandType		getType() const = 0;

  virtual IOperand*		operator+(const IOperand &rhs) const = 0;
  virtual IOperand*		operator-(const IOperand &rhs) const = 0;
  virtual IOperand*		operator*(const IOperand &rhs) const = 0;
  virtual IOperand*		operator/(const IOperand &rhs) const = 0;
  virtual IOperand*		operator%(const IOperand &rhs) const = 0;

  virtual ~IOperand() {};
};

#endif /* !IOPERAND_HH_ */
