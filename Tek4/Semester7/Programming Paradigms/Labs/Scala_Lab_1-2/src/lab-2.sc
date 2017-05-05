/* SECTION 1 */

7 + 13

7 + 13 + 5

def number =  8 + 1

/* SECTION 2 */

def five(): Int = 1 + 4

def addOne(x: Int): Int = x + 1
addOne(4)

def sumInt(x: Int, y: Int): Int = x + y

sumInt(1, sumInt(1, 1))

def squareInt(x: Int): Int = x * x + 1
squareInt(5)

/* SECTION 3 */

def x = 0
def y = {
  def x = 4
  x * x
}
x + y