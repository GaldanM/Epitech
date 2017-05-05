class GenericPair[+T <% Ordered[T]](f: T, s: T) extends ParentGenericPair(f, s){
  private val first: T = f
  private val second: T = s

  def isFirstGreater: Boolean = first > second
  def isSecondGreater: Boolean = second > first
  def areEqual: Boolean = first == second

  override def getFirst: T = first
  override def getSecond: T = second
}

