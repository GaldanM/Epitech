/* 1. */
val fruits: List[String] = List("apples", "oranges", "pears")

/* 2. */
val doubles: List[Double] = List(1.0, 1.0, 2.0, 3.0, 5.0)

/* 3. */
// val doubles2: List[Int] = List(1.0, 1.0, 2.0, 3.0, 5.0)
/*
** It's not possible because we specify that values are floating values
** and we try to put them into a integer list.
*/

/* 4. */
val doubles2 = 1.0 :: (1.0 :: (2.0 :: (3.0 :: (5.0 :: Nil))))

/* 5. */
//val doubles3 = 1.0 ::: (1.0 ::: (2.0 ::: (3.0 ::: (5.0 ::: Nil))))
/*
** It's not working because ':::' operator is used to concat list
** If we wanted something working we could do that :
** val doubles3 = (1.0 :: Nil) ::: (1.0 :: Nil) ::: (2.0 :: Nil) ::: (3.0 :: Nil) ::: (5.0 :: Nil)
*/

/* 6. */
doubles2.head
doubles2.tail
doubles2.tail.tail.head
doubles.last
doubles.init
doubles.init.last
doubles.init.init.last

/* 7. */
val empty = List()
empty.isEmpty
/*
** If we try to use head or tail, Scala will displays something like that :
** "java.util.NoSuchElementException: head of empty list"
*/

/* 8. */
val range = List.range(10, 21)

/* 9. */
val ranges = range.splitAt(3)
ranges._1.length
ranges._2.length

/* 10. */
val ranges2 = List.range(10, 21)
val ranges3 = ranges2.map(x => x - 10)

/* 11. */
ranges3.foreach(x => println(x))

/* 12. */
val filterList = List.range(50, 101).filter(x => x % 5 == 0)

/* 13. */
filterList.length
filterList.count(x => x % 10 == 0)
/*
** Since the lengths are not the same, we can conclude
** that all values weren't dividable by 10
*/

/* 14. */
List.range(10, 31)
  .partition(x => x % 2 == 0)

/* 15. */
val integerToDouble = List.range(1, 5)
  .map(x => x.toDouble)

/* 16. */
def printNumber(x: Double, y: Double) = {
  println(x, y)
  x
}
integerToDouble
integerToDouble.reduceLeft(printNumber)
integerToDouble.reduceRight(printNumber)
/*
** Despite the res15 and res16, it displays how reduce functions works.
** reduceLeft starts from the head of the list sending as parameters the first two elements
** then sending the result of the previous call as the first parameter and the third element in the list
** as the second.
** reduceRight is doing th same thing but from the bottom of the list
*/

/* 17. */
integerToDouble.foldLeft(3)((x, y) => {
  println(x, y)
  x + 1
})
integerToDouble.foldRight(3)((x, y) => {
  println(x, y)
  y + 1
})
/*
** The differences between foldLeft and foldRight are the fact that
** the accumulator is the first parameter on foldLeft while it's the
** second one on foldRight, also, foldLeft begin from the top of the list
** and foldRight begin from the bottom of the list.
*/

/* 18. */
val squares = List.range(5, 11)
squares.foldLeft(1)((acc, nb) => acc * nb * nb)

/* 19. */
case class Book(title: String, authors: List[String], year: Int)

val books: List[Book] = List(
  Book("Structure and Interpretation of Computer Programs",
    List("Abelson, Harold", "Sussman, Gerald J."), 1984),
  Book("Principles of Compiler Design",
    List("Aho, Alfred", "Ullman, Jeffrey"), 1977),
  Book("Programming in Modula-2",
    List("Wirth, Niklaus"), 1982),
  Book("Introduction to Functional Programming",
    List("Bird, Richard"), 1988),
  Book("The Java Language Specification",
    List("Gosling, James", "Joy, Bill", "Steele, Guy",
      "Bracha, Gilad"), 1996)
)
books.filter(b => b.authors
  .count(a =>
    ((a contains "Wirth") && (a contains "Niklaus"))
      || ((a contains "Bird") && (a contains "Richard"))
  ) > 0)

