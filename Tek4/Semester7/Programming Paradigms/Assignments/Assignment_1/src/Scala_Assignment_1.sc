/* 2.1 */
(a: Double, b: Double, c: Double, x: Double) => Math.pow(a * x, 2) + (b * x) + c

/* 2.2 */
/* f(2.0 + 3.0, 2 * 2)
** g(2.0 + 3.0) + h(2 * 2)
** (5.0 + 1) + (g(2 * 2) * (2 * 2) - 1)
** (5.0 + 1) + ((4.0 + 1) * (2 * 2) - 1)
*/

/* 2.3 */
def fibonacci(n: Int): Int = {
  if (n <= 1)
    n
  else {
    fibonacci(n - 1) + fibonacci(n - 2)
  }
}
fibonacci(0)
fibonacci(1)
fibonacci(2)
fibonacci(3)
fibonacci(4)
fibonacci(5)
fibonacci(6)

/* 2.4 */
/* a. */
def series(n: Int): Double = {
  def nestedSeries(prev: Double, actual: Double, counter: Int, n: Int): Double = {
      if (counter == n)
        actual
      else {
        val next = (Math.pow(-1, counter) * (5 * actual)) + (Math.pow(-1, counter - 1) * 3 * prev)
        nestedSeries(actual, next, counter + 1, n)
      }
  }
  if (n == 1 || n == 2) if (n == 1) 3 else 5 else nestedSeries(3, 5, 3, n + 1)
}
series(1)
series(2)
series(3)
series(4)
series(5)
series(6)

/*
** b.
** It's tail-recursive because it's evaluation is a square :
** series(4)
** nestedSeries(3, 5, 3, 5)
** nestedSeries(5, -16, 4, 5)
** nestedSeries(-16, -95, 5, 5)
** -95
*/

/* 2.5 */
/* a. */
def higher(f: (Int, Int) => Boolean, g: (Int) => Boolean, x: Int, y: Int): Boolean = f(x, y) && (g(x) || g(y))

/* b. */
def greaterThan(a: Int, b: Int) = a > b
def greaterThan0(x: Int) = x > 0

higher(greaterThan, greaterThan0, 2, 1)
higher(greaterThan, greaterThan0, 1, 2)
higher(greaterThan, greaterThan0, -1, -2)
higher(greaterThan, greaterThan0, -2, -1)

/* c. */
def curriedHigher(f: (Int, Int) => Boolean, g: (Int) => Boolean) = (x: Int, y: Int) => f(x, y) && (g(x) || g(y))

curriedHigher(greaterThan, greaterThan0)(2, 1)
curriedHigher(greaterThan, greaterThan0)(1, 2)
curriedHigher(greaterThan, greaterThan0)(-1, -2)
curriedHigher(greaterThan, greaterThan0)(-2, -1)

