object Main {
 def main(args: Array[String]): Unit = {
   /* PART ONE */
   println("PART ONE\n")

   /* 1. and 2. */
   val firstPair: GenericPair[String] = new GenericPair[String]("Hello", "World")
   println(firstPair.getFirst + " " + firstPair.getSecond + " !")

   val secondPair: GenericPair[Double] = new GenericPair[Double](12.5, 29.92)
   println(secondPair.getFirst + secondPair.getSecond)

   /* 3. */
   println(firstPair.isFirstGreater)
   println(secondPair.isSecondGreater)

   /* 4. */
   val thirdPair: GenericPair[java.lang.Integer] = new GenericPair[java.lang.Integer](10, 20)
   println(thirdPair.getFirst.toString + " " + thirdPair.getSecond.toString)

   /* 5. and 6. */
   val fourthPair: GenericPair[scala.math.ScalaNumber] = new GenericPair[scala.math.BigInt](scala.math.BigInt("1500"), scala.math.BigInt("500"))
   println(fourthPair.getFirst.toString + " " + fourthPair.getSecond.toString)

   /* 7. */
   val fifthPair: ParentGenericPair[String, Double] = new ParentGenericPair[String, Double]("Hello !", 42)
   println(fifthPair.getFirst.toString + " " + fifthPair.getSecond.toString)

   /* 8. */
   /*
   ** It's impossible to move the methods because the two parameters aren't the same type
   */


   /* PART TWO */
   println("\nPART TWO\n")

   /* 1. */
   val cart: ShoppingCart = new ShoppingCart
   cart.addProduct("Shampoo")
   cart.addProduct("Shoes")
   println(cart)
   println("The cart is worth " + cart.calcWorth().toString + "€")
   cart.removeProduct("Shoes")
   println(cart)
   println("The cart is worth " + cart.calcWorth().toString + "€\n")

   /* 2. */
   var calc = new SimpleCalculator(4)
   println(calc)
   calc = calc.add(2)
   println(calc)
   calc = calc.sub(3)
   println(calc)
   calc = calc.mul(4)
   println(calc)
   calc = calc.div(5)
   println(calc)
   calc = calc.squared()
   println(calc)
   calc = calc.sqrt()
   println(calc)
 }
}