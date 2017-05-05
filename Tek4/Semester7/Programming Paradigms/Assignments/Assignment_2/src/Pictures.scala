abstract class Picture {

}

class SingleRowPicture(r: Row) extends Picture {
  val row: Row = r

  override def toString: String = row.toString
}

class DoubleRowPicture(r1: Row, r2: Row) extends Picture {
  val firstRow: Row = r1
  val secondRow: Row = r2

  override def toString: String = firstRow.toString + "\n" + secondRow.toString
}

class TripleRowPicture(r1: Row, r2: Row, r3: Row) extends Picture {
  val firstRow: Row = r1
  val secondRow: Row = r2
  val thirdRow: Row = r3

  override def toString: String = firstRow.toString + "\n" + secondRow.toString + "\n" + thirdRow.toString
}