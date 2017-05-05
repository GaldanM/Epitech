import java.text.DecimalFormat

class Complex(r: Double, i: Double) extends INumber {
  def this(r: Double) = this(r, 0)

  def real: Double = r

  def imaginary: Double = i

  def conjugate: Complex = new Complex(this.real, this.imaginary * -1)

  def df: DecimalFormat = new DecimalFormat("0.##")

  /* PROBLEMS WITH INUMBER */

  override def add: Complex => Complex = (n: Complex) => {
    new Complex(
      this.real + n.real,
      this.imaginary + n.imaginary
    )
  }

  override def sub: Complex => Complex = (n: Complex) => {
    new Complex(
      this.real - n.real,
      this.imaginary - n.imaginary
    )
  }

  override def mul: Complex => Complex = (n: Complex) => {
    val f = this.real * n.real
    val o = this.real * n.imaginary
    val i = this.imaginary * n.real
    val l = this.imaginary * n.imaginary * -1
    new Complex(f + l, o + i)
  }

  override def div: Complex => Complex = (n: Complex) => {
    val numerator = this.mul(n.conjugate)
    val denominator = n.mul(n.conjugate)
    require(denominator.real != 0)
    new Complex(numerator.real / denominator.real, numerator.imaginary / denominator.real)
  }

  def sqrt(): Complex = {
    val real = Math.pow(this.real, 2) - Math.pow(this.imaginary, 2)
    val imaginary = 2 * this.real * this.imaginary
    new Complex(real, imaginary)
  }

  def +(c: Complex): Complex = this.add(c)

  def -(c: Complex): Complex = this.sub(c)

  def *(c: Complex): Complex = this.mul(c)

  def /(c: Complex): Complex = this.div(c)

  override def toString: String = {
    df.format(r) +
      (if (i < 0) " - " else if (i > 0) " + ") +
      (if (i != 0) (if (i != 1 && i != -1) df.format(Math.abs(i)) else "") + "i" else "")
  }
}
