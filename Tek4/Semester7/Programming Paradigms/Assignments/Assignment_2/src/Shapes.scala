abstract class Shape {
  val colour: String
}

class Square(s: Double, c: String) extends Shape {
  val side: Double = s

  override val colour: String = c
  val area: Double = side * side

  override def toString: String = "S(" + colour + ")"
}

class Triangle(b: Double, h: Double, c: String) extends Shape {
  val base: Double = b
  val height: Double = h

  override val colour: String = c
  val area: Double = base * height / 2

  override def toString: String = "T(" + colour + ")"
}

class Circle(r: Double, c: String) extends Shape {
  val radius: Double = r

  override val colour: String = c
  val area: Double = Math.PI * radius * radius

  override def toString: String = "C(" + colour + ")"
}