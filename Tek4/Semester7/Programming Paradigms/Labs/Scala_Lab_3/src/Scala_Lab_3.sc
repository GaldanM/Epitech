/* 1. */
def Number = 5
val Floating = 5.2
var Sentence = "Hello World !"

/* 2. */
def Number2: Int = 5
val Floating2: Double = 5.2
var Sentence2: String = "Hello World !"

/* 3. */
//Number = 6
//Floating = 4.2
Sentence = "World Hello !"
/*
** We can only change the "var"
*/

/* 4. */
def average(x: Int, y: Int): Double = {
  def res: Double = x + y
  res / 2
}
average(1, 2)
average(1, 3)
average(5, 10)

/* 5. */
def average2(x: => Int, y: => Int): Double = {
  (x + y) / 2
}
average2(1, 2)
average2(1, 3)
average2(5, 10)
/*
** We can see that we no longer need Double object
** to return a Double as well
*/

/* 6. */
def func(p: Int): Int = 42
func(4)

/* 7. */
def loop: Int = loop
//func(loop)
/*
** This function call itself recursively
*/

/* 8. */
def func2(p: => Int): Int = 42
func2(loop)
/*
** It does not loop because the parameter is not evaluated
** so it does not call the function loop
*/

/* 9. */
def term(Number: Int): Int = {
  if (Number % 2 == 0)
    Number / 2
  else
    (Number * 3) + 1
}
term(4)
term(5)

/* 10. */
def func3(n: Int): Int = {
  if (n == 1)
    n
  else
    func3(term(n))
}
func3(3)

/* 11. */
def func4(n: Int): Int = {
  if (n == 1)
    n
  else {
    println(n)
    func4(term(n))
  }
}
func4(50)

/* 12. */
def func5(n: Int): Int = {
  def internalTerm(Num: Int): Int = {
    if (Num % 2 == 0)
      Num / 2
    else
      (Num * 3) + 1
  }
  if (n == 1)
    n
  else {
    println(n)
    func5(internalTerm(n))
  }
}
func5(50)

/* 13. */
def func6(x: Int): Int = {
  def multiply(acc: Int, x: Int): Int = {
    if (x < 1)
      acc
    else
      multiply(acc * x, x - 1)
  }
  multiply(1, x)
}
func6(5)