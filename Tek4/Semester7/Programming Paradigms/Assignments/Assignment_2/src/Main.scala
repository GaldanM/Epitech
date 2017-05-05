object Main {
  def main(args: Array[String]): Unit = {
    //    Test for Problem 1 - 2 - 3
    val testTriplePicture = new TripleRowPicture(
      new DoubleShapeRow(new Square(5, "r"), new Triangle(3, 3, "g")),
      new SingleShapeRow(new Circle(8, "b")),
      new TripleShapeRow(new Square(2, "r"), new Triangle(4, 9, "g"), new Circle(6, "b"))
    )
    println(testTriplePicture)

    //    Test for Problem 4
    val compressor = new GreatAreaCompressor
    println(compressor.calculateArea(testTriplePicture))
    println(compressor.calculateArea(new DoubleRowPicture(
      new SingleShapeRow(new Square(5, "r")),
      new SingleShapeRow(new Triangle(5, 5, "g"))
    )))
  }
}