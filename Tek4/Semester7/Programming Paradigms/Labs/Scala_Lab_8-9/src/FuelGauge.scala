class FuelGauge {
  var fuelGallons: Double = 0

  def incFuel(): Unit = {
    require(this.fuelGallons + 1 <= 15)
    this.fuelGallons += 1
  }

  def decFuel(): Unit = {
    require(this.fuelGallons - 1 >= 0)
    this.fuelGallons -= 1
  }

  def reportGallons: Double = this.fuelGallons
}

class ElectronicFuelGauge extends FuelGauge {
  override def toString: String = "There is currently " + this.fuelGallons + " gallons in the tank"
}

class AnalogFuelGauge extends FuelGauge {
  override def toString: String = {
    if (this.fuelGallons == 15)
      "Tank is full"
    else if (this.fuelGallons < 15 && this.fuelGallons >= 12)
      "Tank is 3/4 full"
    else if (this.fuelGallons < 12 && this.fuelGallons >= 8)
      "Tank is 1/2 full"
    else if (this.fuelGallons < 8 && this.fuelGallons >= 4)
      "Tank is 1/4 full"
    else
      "Tank is empty"
  }
}
