final class SimpleCalculator(init: Double) {
  def this() = this(1)
  
  private val res: Double = init
  
  def add(toAdd: Double): SimpleCalculator = new SimpleCalculator(this.res + toAdd)
  def sub(toSub: Double): SimpleCalculator = new SimpleCalculator(this.res - toSub)
  def mul(toMul: Double): SimpleCalculator = new SimpleCalculator(this.res * toMul)
  def div(toDiv: Double): SimpleCalculator = new SimpleCalculator(this.res / toDiv)
  def squared(): SimpleCalculator = new SimpleCalculator(Math.pow(this.res, 2))
  def sqrt(): SimpleCalculator = new SimpleCalculator(Math.sqrt(this.res))

  override def toString: String = this.res.toString
}
