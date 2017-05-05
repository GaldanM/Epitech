abstract class Car(g: FuelGauge, o: Odometer) {

  val gauge: FuelGauge = g

  val odometer: Odometer = o

  def simulation(): Unit = {
    for (_ <- 0 until 15) this.gauge.incFuel()
    while (this.gauge.fuelGallons > 0) {
      this.odometer.incMiles(this.gauge)
      println(this.odometer)
      println(this.gauge)
      println()
    }
  }
}

class MechanicalCar extends Car(new AnalogFuelGauge, new MechanicalOdometer) {

}

class ElectricCar extends Car(new ElectronicFuelGauge, new ElectronicOdometer) {

}