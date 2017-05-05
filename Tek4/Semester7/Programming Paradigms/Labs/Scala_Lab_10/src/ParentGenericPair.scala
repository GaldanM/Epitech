class ParentGenericPair[+T <% Ordered[T], +S <% Ordered[S]](f: T, s: S) {
  private val first: T = f
  private val second: S = s

  def getFirst: T = first
  def getSecond: S = second
}

