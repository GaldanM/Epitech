abstract class Row {

}

class SingleShapeRow(s: Shape) extends Row {
  val shape: Shape = s

  override def toString: String = "| " + shape.toString + " |"
}

class DoubleShapeRow(s1: Shape, s2: Shape) extends Row {
  val firstShape: Shape = s1
  val secondShape: Shape = s2

  override def toString: String = {
    "| " + firstShape.toString + " | " + secondShape.toString + " |"
  }
}

class TripleShapeRow(s1: Shape, s2: Shape, s3: Shape) extends Row {
  val firstShape: Shape = s1
  val secondShape: Shape = s2
  val thirdShape: Shape = s3

  override def toString: String = "| " + firstShape.toString + " | " + secondShape.toString + " | " + thirdShape.toString + " |"
}