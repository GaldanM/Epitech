object Main {
  def main(args: Array[String]): Unit = {
    val driver = new Driver
    val eCar: Car = new ElectricCar
    driver.driveCar(eCar)
    eCar.simulation()

    val mCar: Car = new MechanicalCar
    driver.driveCar(mCar)
    mCar.simulation()
  }
}