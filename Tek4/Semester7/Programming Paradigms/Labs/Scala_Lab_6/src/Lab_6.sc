/* 1. */
case class Address(street_name: String, city: String, country: String)

/* 2. */
val ad = Address("Phoenix Court", "Dublin", "Ireland")
val ad2 = new Address("Phoenix Court", "Dublin", "Ireland")
val ad3 = Address.apply("Phoenix Court", "Dublin", "Ireland")

/*
** All of the three possibilities are possible.
*/

/* 3. */
//val ad4 = Address("Phoenix Court")

/*
** Creating an instance without all attribute is not possible
*/

/* 4. */
ad.street_name
//ad.street_name = "State Avenue"

/*
** It's not possible to re-assign since attributes are defined as "val"
*/

/* 5 .*/
ad.toString

/* 6. */
Address.unapply(ad)

/* 7. */
case class Person(first_name: String, last_name: String, address: Address)

/* 8. */
def funcMatch(str: String) = str match {
  case "A" => println("The string is an A")
  case "B" => println("The string is a B")
  case "C" => println("The string is a C")
  case _ =>  println("Unknown string")
}

funcMatch("A")
funcMatch("B")
funcMatch("C")
funcMatch("D")

/* 9. */
def funcMatch2(numb: Int) = numb match {
  case `numb` if numb % 2 == 0 => "The number is even"
  case _ => "The number is odd"
}

funcMatch2(2)
funcMatch2(3)

/* 10. */
def funcMatchPerson(p: Person): String = p match {
  case Person(_, _, Address(_, _, "Ireland")) => "Hiya " + p.first_name + "!"
  case _ => "Hello stranger from " + p.address.country
}

funcMatchPerson(Person("Brian", "O'Conner", Address("O'Connell Steet", "Dublin", "Ireland")))
funcMatchPerson(Person("Galdan", "Moulinneuf", Address("Rue de la Fosse aux Bergers", "Villemomble", "France")))

/* 11. */
def funcMatchPersonComplex(p: Person): String = p match {
  case Person(_, _, Address(_, _, "Ireland")) => "Hiya " + p.first_name + "!"
  case Person(_, _, Address(_, "Dublin", _)) => "Hello fellow companion from Dublin !!"
  case Person(_, "Dupont", Address(_, _, "France")) => "Oh ! Omelette du fromage !"
  case Person("Michel", "Dupond", Address("Rue des Lavandes", "Paris", "France")) => "Hello Mr.Dupond, how's the things going in Paris ?"
  case _ => "Hello stranger from " + p.address.country
}

/* 12. */
def calculateSum(list: List[Int]): Int = list match {
  case head :: tail =>
    calculateSum(tail) + head
  case _ => 0
}

calculateSum(List.range(1, 10))

/* 13. */
def filterOdd(list: List[Int]): List[Int] = list match {
  case head :: tail =>
    if (head % 2 == 0) {
      List(head) ::: filterOdd(tail)
    } else {
      filterOdd(tail)
    }
  case _ => list
}

filterOdd(List.range(1, 11))

/* 14. */
def organizeEvenOdd(list: List[Int]): List[Int] = list match {
  case head :: tail =>
    if (head % 2 != 0) {
      List(head) ::: organizeEvenOdd(tail)
    } else {
      organizeEvenOdd(tail) ::: List(head)
    }
  case _ => list
}

organizeEvenOdd(List.range(1, 11))

//________________________________________________________________

/* 1. */
for (x <- List.range(1, 11)) yield x * 2

/* 2. */
for (x <- List.range(1, 10)) yield Math.sqrt(x)

/* 3. */
for { x <- List.range(1, 10)
      y <- List.range(1, 3)
} yield Math.sqrt(x)

/*
** Each element will be doubled in the list
** because there is 2 elements in the second generator.
** If I put 1 element in the second generator,
** the result with 2. will be the same
*/

/* 4. */
for (x <- List.range(50, 101) if x % 5 == 0) yield x

/* 5. */
case class Book(title: String, authors: List[String])
val books: List[Book] = List(
  Book("Structure and Interpretation of Computer Programs",
    List("Abelson, Harold", "Sussman, Gerald J.")),
  Book("Principles of Compiler Design",
    List("Aho, Alfred", "Ullman, Jeffrey")),
  Book("Programming in Modula-2",
      List("Wirth, Niklaus")),
  Book("Introduction to Functional Programming",
    List("Bird, Richard")),
  Book("The Java Language Specification",
    List("Gosling, James", "Joy, Bill", "Steele, Guy", "Bracha, Gilad")))

for (x <- books if x.authors.exists(_.contains("Ullman"))) yield x

/* 6. */
for (x <- books if x.title.contains("Program")) println(x)

/* 7. */
def multipleAuthors(list: List[Book]): List[Book] =
  for (b <- books if b.authors.length > 1) yield b

multipleAuthors(books)