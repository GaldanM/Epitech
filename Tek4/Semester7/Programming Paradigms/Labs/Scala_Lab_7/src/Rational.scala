class Rational(x: Int, y: Int) extends INumber {
  require(y > 0, "Denominator must be positive")

  def numerator: Int = x

  def denominator: Int = y

  override def add: Rational => Rational = (n: Rational) => {
    new Rational(
      (this.numerator * n.denominator) + (this.denominator * n.numerator),
      this.denominator * n.denominator
    )
  }

  override def sub: Rational => Rational = (n: Rational) => {
    new Rational(
      (this.numerator * n.denominator) - (this.denominator * n.numerator),
      this.denominator * n.denominator
    )
  }

  override def mul: Rational => Rational = (n: Rational) => {
    new Rational(
      this.numerator * n.numerator,
      this.denominator * n.denominator
    )
  }

  override def div: Rational => Rational = (n: Rational) => {
    this.mul(new Rational(
      n.denominator,
      n.numerator
    ))
  }

  def +(r: Rational): Rational = this.add(r)

  def -(r: Rational): Rational = this.sub(r)

  def *(r: Rational): Rational = this.mul(r)

  def /(r: Rational): Rational = this.div(r)

  override def toString: String = numerator + "/" + denominator
}

