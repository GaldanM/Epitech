abstract class Odometer() {
  var miles: Double = 0

  def incMiles(g: FuelGauge): Unit = {
    if (this.miles == 999999)
      this.reset()
    else
      this.miles += 1
    if (this.miles % 24 == 0)
      g.decFuel()
  }

  def reset(): Unit = {
    this.miles = 0
  }
}

class ElectronicOdometer extends Odometer () {
  override def toString: String = "The electric car is currently " + this.miles + " miles old"

}

class MechanicalOdometer extends Odometer () {
  override def toString: String = "This mechanical car is currently " + this.miles + " miles old"
}