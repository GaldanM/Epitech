class GreatAreaCompressor {
  def calculateArea(x: Any): Double = x match {
    case srp: SingleRowPicture => this.matchRow(srp.row)
    case drp: DoubleRowPicture => this.matchRow(drp.firstRow) + this.matchRow(drp.secondRow)
    case trp: TripleRowPicture => this.matchRow(trp.firstRow) + this.matchRow(trp.secondRow) + this.matchRow(trp.thirdRow)

    case ssr: SingleShapeRow => this.matchShape(ssr.shape)
    case dsr: DoubleShapeRow => this.matchShape(dsr.firstShape) + this.matchShape(dsr.secondShape)
    case tsr: TripleShapeRow => this.matchShape(tsr.firstShape) + this.matchShape(tsr.secondShape) + this.matchShape(tsr.thirdShape)

    case sq: Square => this.getSquareArea(sq)
    case tr: Triangle => this.getTriangleArea(tr)
    case ci: Circle => this.getCircleArea(ci)

    case _ => 0
  }

  private[this] def matchRow(r: Row): Double = r match {
    case ssr: SingleShapeRow => this.matchShape(ssr.shape)
    case dsr: DoubleShapeRow => this.matchShape(dsr.firstShape) + this.matchShape(dsr.secondShape)
    case tsr: TripleShapeRow => this.matchShape(tsr.firstShape) + this.matchShape(tsr.secondShape) + this.matchShape(tsr.thirdShape)
  }

  private[this] def matchShape(s: Shape): Double = s match {
    case sq: Square => this.getSquareArea(sq)
    case tr: Triangle => this.getTriangleArea(tr)
    case ci: Circle => this.getCircleArea(ci)
  }

  private[this] def getSquareArea(sq: Square): Double = sq.side * sq.side
  private[this] def getTriangleArea(tr: Triangle): Double = tr.base * tr.height / 2
  private[this] def getCircleArea(ci: Circle): Double = Math.PI * ci.radius * ci.radius
}
