/* 1. */
def factorialNotTailRecursive(x: Int): Int = {
  if (x == 0)
    1
  else
    x * factorialNotTailRecursive(x - 1)
}
factorialNotTailRecursive(5)


/* 2. */
/*
** It's not because the evaluation is a triangle :
** factorialNotTailRecursive(5)
** 5 * factorialNotTailRecursive(4)
** 5 * (4 * factorialNotTailRecursive(3))
** 5 * (4 * (3 * factorialNotTailRecursive(2)))
** 5 * (4 * (3 * (2 * factorialNotTailRecursive(1))))
** 5 * (4 * (3 * (2 * (1 * factorialNotTailRecursive(0)))))
** 5 * (4 * (3 * (2 * (1 * 1))))
** 120
*/

/* 3. */
def factorialTailRecursive(n: Int): Int = {
  require (n >= 0)
  def factorial(n: Int, accum: Int): Int = {
    if (n == 0)
      accum
    else
      factorial(n - 1, accum * n)
  }
  factorial(n, 1)
}
factorialTailRecursive(5)


/* 4. */
/*
** It's tail-recursive because the evaluation is a square :
** factorialTailRecursive(5)
** factorial(5, 4)
** factorial(20, 3)
** factorial(60, 2)
** factorial(120, 1)
** factorial(120, 0)
** 120
*/


/* 5. */
def series(start: Int, ratio: Int, pos: Int): Int = {
  if (pos == 1)
    start
  else
    series(start * ratio, ratio, pos - 1)
}
series(1, 2, 1)
series(1, 2, 2)
series(1, 2, 3)
series(1, 2, 4)


/* 6. */
/*
** In the same way as 4., evaluation is a square :
** series(1, 2, 3)
** series(2, 2, 2)
** series(4, 2, 1)
** 4
*/


/* 7. */
def id(param: Double): Double = param

def square(param: Double): Double = param * param

def cube(param: Double): Double = param * param * param

id(2)
square(2)
cube(2)


/* 8. */
(param: Double) => param
(param: Double) => param * param
(param: Double) => param * param * param


/* 9. */
def higher(paramFunc: Double => Double, param2: Double): Double = paramFunc(param2) * 2 - 1
higher((param: Double) => param, 5)
higher((param: Double) => param * param, 5)
higher((param: Double) => param * param * param, 5)


/* 10. */
(x: Int, y: Int) => Math.pow(x, y)


/* 11. */
def powFactory() = (x: Int, y: Int) => Math.pow(x, y)


/* 12. */
def greaterThan(n: Double) = (m: Double) => m > n

def greaterThan10 = greaterThan(10)

greaterThan10(20)
greaterThan10(9)


/* 13. */
def powWrapper(a: Double) = (b: Double) => Math.pow(a, b)

powWrapper(2)(3)

def pow2(x: Double) = powWrapper(2)(x)

pow2(3)
