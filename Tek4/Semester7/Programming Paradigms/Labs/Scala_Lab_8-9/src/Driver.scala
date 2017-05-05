class Driver {
  var car: Car = _

  def driveCar(c: Car): Unit = {
    this.car = c
    println(this)
  }

  override def toString: String = {
    if (this.car.isInstanceOf[MechanicalCar])
      "I'm driving a mechanical car !"
    else
      "I'm driving an electric car !"
  }
}
