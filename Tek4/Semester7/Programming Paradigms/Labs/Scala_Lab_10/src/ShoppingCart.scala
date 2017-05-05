class ShoppingCart {
  private var cart: List[String] = List()

  def addProduct(p: String): Unit = this.cart = p :: this.cart
  def removeProduct(p: String): Unit = this.cart = this.cart.filter(s => s != p)
  def calcWorth(): Double = this.cart.length * 2

  override def toString: String = {
    var s: String = ""
    this.cart.foreach(p => s = s + p + (if (this.cart.last != p) ", " else ""))
    s
  }
}
