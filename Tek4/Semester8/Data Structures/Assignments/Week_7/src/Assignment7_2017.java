import java.util.*;
import java.util.function.*;

public class Assignment7_2017 {
    public static void main(String args[]) {
    /*QUESTION 1 ==========================================================
    Using the class NewNumbers listed below write a code sequence that tests
    the methods: 
      forAll(Predicate<Integer> pr),
      List<Integer> getSubList(Predicate<Integer> pr)
      List<Integer> mapList(Function<Integer,Integer> f)
      Sample tests might be: all the values are positive, all negative,
      retrieve a list of the even numbers, a list of negative numbers,
      use mapList to return the square of all the numbers, etc
      You should write at least three tests for each method
    ======================================================================*/
        System.out.println("-------------------- QUESTION 1 --------------------\n");

        // This code sets up a List
        NewNumbers lst = new NewNumbers();
        lst.add(Arrays.asList(1, 2, 3, 4, 6, -1, -5, 7, 8, 12, 4, -5, 0, 0, 1, 4, -2, 0));
        lst.print(x -> System.out.print(x + " "));
        System.out.println();

        System.out.println("-------------------- TESTS forAll --------------------\n");
        System.out.println(lst.forAll(x -> x % 2 != 0));
        System.out.println(lst.forAll(x -> x % 2 == 0));
        System.out.println(lst.forAll(x -> x == 42));
        System.out.println("\n-------------------- END TESTS forAll --------------------\n");

        System.out.println("-------------------- TESTS getSubList --------------------\n");
        System.out.println(lst.getSubList(x -> x > 0));
        System.out.println(lst.getSubList(x -> x < 0));
        System.out.println(lst.getSubList(x -> x == 0));
        System.out.println("\n-------------------- END TESTS getSubList --------------------\n");

        System.out.println("-------------------- TESTS mapList --------------------\n");
        Function<Integer, Integer> square = x -> x * x;
        Function<Integer, Integer> cube = x -> square.apply(x) * x;
        Function<Integer, Integer> abs = x -> ((x >> 31) ^ x) - (x >> 31);
        System.out.println(lst.mapList(square));
        System.out.println(lst.mapList(cube));
        System.out.println(lst.mapList(abs));
        System.out.println("\n-------------------- END TESTS mapList --------------------\n");

        System.out.println("-------------------- END QUESTION 1 --------------------\n\n\n");
    /*QUESTION 2 ============================================================
    Using the generic class MyList<E> listed below write a code sequence that 
    tests all of its the methods. You are given a Book class that you can use 
    to perform your tests. Note that creating a MyList<Integer> instance is not
    an acceptable data type for your tests.
    ================================================================== */
        System.out.println("-------------------- QUESTION 2 --------------------\n");

        MyList<Book> books = new MyList<>();
        List<Book> books2 = new ArrayList<>();

        System.out.println("-------------------- TESTS WITH BOOKS --------------------\n");
        books.add(new Book("Foo", "Bar"));
        books.add(new Book("Bar", "Foo"));
        books.add(new Book("Scala Programming", "Jacek"));
        books.add(new Book("Windows 7", "Bill Gates"));
        books.add(new Book("Windows 10", "Bill Gates"));
        books.print(b -> System.out.print(b.title() + " by " + b.author() + " | "));
        books2.add(new Book("Foo", "Bar"));
        books2.add(new Book("Bar", "Foo"));
        books2.add(new Book("Scala Programming", "Jacek"));
        books2.add(new Book("Windows 7", "Bill Gates"));
        books2.add(new Book("Windows 10", "Bill Gates"));
        books.add(books2);
        books.print(b -> System.out.print(b.title() + " by " + b.author() + " | "));

        System.out.println(books.contains(b -> b.title().equals("Scala Programming")));
        System.out.println(books.contains(b -> b.title().equals("OCaml Programming")));
        System.out.println(books.filterList(b -> b.author().equals("Bill Gates")));
        books.remove(b -> b.author().equals("Bill Gates"));
        books.print(b -> System.out.print(b.title() + " by " + b.author() + " | "));
        System.out.println("\n-------------------- END TESTS WITH BOOKS --------------------\n");

        System.out.println("-------------------- TESTS WITH STRINGS --------------------\n");
        MyList<String> sentences = new MyList<>();
        List<String> sentences2 = new ArrayList<>();

        sentences.add("Hello !");
        sentences.add("Oh, hello there, how are you ?");
        sentences.add("I'm fine, you ?");
        sentences.add("Good !");
        sentences.print(str -> System.out.print(str + " | "));
        sentences2.add("Hello !");
        sentences2.add("Oh, hello there, how are you ?");
        sentences2.add("I'm fine, you ?");
        sentences2.add("Good !");
        sentences.add(sentences2);
        sentences.print(str -> System.out.print(str + " | "));

        System.out.println(sentences.contains(str -> str.equals("Hello !")));
        System.out.println(sentences.contains(str -> str.equals("I'm not in there")));
        System.out.println(sentences.filterList(str -> str.contains("!")));
        sentences.remove(str -> str.contains("!"));
        sentences.print(str -> System.out.print(str + " | "));
        System.out.println("\n-------------------- END TESTS WITH STRINGS --------------------");
        System.out.println("\n-------------------- END QUESTION 2 --------------------\n");

    }
}

class NewNumbers {
    private List<Integer> data = new ArrayList<>();

    void add(int x) {
        data.add(x);
    }

    void add(List<Integer> lst) {
        data.addAll(lst);
    }

    boolean contains(Predicate<Integer> pr) {
        for (Integer x : data)
            if (pr.test(x)) return true;
        return false;
    }

    boolean forAll(Predicate<Integer> pr) {
        for (Integer x : data)
            if (!pr.test(x))
                return false;
        return true;
    }

    List<Integer> getSubList(Predicate<Integer> pr) {
        List<Integer> tmp = new ArrayList<>();
        for (Integer x : data)
            if (pr.test(x))
                tmp.add(x);
        return tmp;
    }

    List<Integer> mapList(Function<Integer, Integer> f) {
        List<Integer> tmp = new ArrayList<>();
        for (Integer x : data)
            tmp.add(f.apply(x));
        return tmp;
    }

    int count(Predicate<Integer> pr) {
        int count = 0;
        for (Integer x : data)
            if (pr.test(x))
                count++;
        return count;
    }

    int sum(Predicate<Integer> pr) {
        int s = 0;
        for (Integer x : data)
            if (pr.test(x))
                s += x;
        return s;
    }

    void print(Consumer<Integer> cn) {
        data.forEach(cn);
        System.out.println();
    }
}

class MyList<E> implements Iterable<E> {
    private List<E> data = new LinkedList<>();

    public void add(E x) {
        data.add(x);
    }

    public void add(List<E> ls) {
        data.addAll(ls);
    }

    public boolean contains(Predicate<E> pr) {
        for (E x : data)
            if (pr.test(x))
                return true;
        return false;
    }

    public List<E> filterList(Predicate<E> pr) {
        List<E> tmp = new LinkedList<>();
        for (E x : data)
            if (pr.test(x))
                tmp.add(x);
        return tmp;
    }

    public void remove(Predicate<E> pr) {
        data.removeIf(pr);
    }

    public void print(Consumer<E> cn) {
        data.forEach(cn);
        System.out.println();
    }

    public Iterator<E> iterator() {
        return data.iterator();
    }
}

class Book {
    private String title;
    private String author;

    public Book(String t, String a) {
        title = t;
        author = a;
    }

    public String title() {
        return title;
    }

    public String author() {
        return author;
    }

    public boolean equals(Object ob) {
        if (!(ob instanceof Book))
            return false;
        Book b = (Book) ob;
        return title.equals(b.title) && author.equals(b.author);
    }

    public int hashCode() {
        return 31 * title.hashCode() * author.hashCode();
    }

    public String toString() {
        return title + " " + author;
    }
}