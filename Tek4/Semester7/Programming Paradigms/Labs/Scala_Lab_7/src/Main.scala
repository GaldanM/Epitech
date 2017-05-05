object Main {
  def main(args: Array[String]): Unit = {
    val c1 = new Complex(2.4, 1)
    println(c1)
    val c2 = c1 + new Complex(3, -7)
    println(c2)
    val c3 = c2 - new Complex(-2, 5)
    println(c3)
    val c4 = new Complex(1, -3) * new Complex(2, 5)
    println(c4)
    val c5 = new Complex(6, 3) / new Complex(7, 0)
    println(c5)
    val c6 = new Complex(8, -6).sqrt()
    println(c6)

    val r1 = new Rational(5, 1)
    println(r1)
    val r2 = r1.add(new Rational(2, 3))
    println(r2)
    val r3 = r2.sub(new Rational(2, 3))
    println(r3)
    val r4 = r3.mul(new Rational(2, 3))
    println(r4)
    println(r4.div(new Rational(2, 3)))
  }
}