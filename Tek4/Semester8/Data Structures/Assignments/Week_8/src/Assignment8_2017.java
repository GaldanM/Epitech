/**
 * student name: Galdan MOULINNEUF
 * student number: 2927686
 */

import java.util.*;
import java.util.function.Predicate;

public class Assignment8_2017 {
    private static void testList(int n) {
        MyHashList<Point> lst = new MyHashList<>(n);
        for (int i = 0; i < 10000; ++i) {
            lst.add(new Point((int) (Math.random() * 100), (int) (Math.random() * 100)));
        }
        System.out.println("\n------------------TEST WITH " + n + " LISTS--------------\n");
        System.out.println("Usage : " + lst.percentUsed() + "% with " + lst.empty() + " lists empty");
        System.out.println("Largest : " + lst.largestBucket() + " elements in a list");
        System.out.println("Smallest : " + lst.smallestBucket() + " elements in a list\n");
        int[] lists = lst.listSizes();
        int count = n - lst.empty();
        for (int i = lists.length - 1; i >= 0; --i) {
            if (count > 0)
                System.out.println("Lists with " + i + " elements = " + lists[i]);
            if (lists[i] != 0)
                --count;
        }
        System.out.println("\n---------------END TEST WITH " + n + " LISTS-----------\n");
    }

    private static void Question1() {
        System.out.println("--------------- QUESTION 1 ---------------");

        testList(1);        // 1 is way too small and has lot of empty list and lot of elements into one list

        testList(10000);    // 100000 is way too small since there is nearly 70% of lists that are empty,
        // but there are only approximately 11 elements at best in a list.

        testList(5000);     // 5000 is still too much with 40% of unused list but nearly 11 elements in a list at most,
        // which is good.

        testList(1000);     // 1000 is a little too small, there are no empty lists and that's good
        // but there are nearly 24 elements in a list, which is not optimized enough

        testList(2000);     // 2000 seems to be a good compromise, sometimes, lists are not empty at all,
        // sometimes there are some but no more than 3%.
        // Plus, the max elements in a list is nearly 17.
        System.out.println("------------- END QUESTION 1 -------------\n");
    }

    private static void Question2() {
        System.out.println("\n--------------- QUESTION 2 ---------------\n");
        int n = 2;
        MyHashList<Integer> lst = new MyHashList<>(n);
        Integer i1 = 0;
        Integer i2 = 1;
        Integer i3 = 1;
        Integer i4 = 2;
        Integer i5 = 3;
        Integer i6 = 6;

        System.out.println("Indexes for each points : " +
                "\ni1 = " + Math.abs(i1.hashCode() % n) +
                "\ni2 = " + Math.abs(i2.hashCode() % n) +
                "\ni3 = " + Math.abs(i3.hashCode() % n) +
                "\ni4 = " + Math.abs(i4.hashCode() % n) +
                "\ni5 = " + Math.abs(i5.hashCode() % n) +
                "\ni6 = " + Math.abs(i6.hashCode() % n));

        lst.add(i1);
        lst.add(i2);
        lst.add(i3);
        lst.add(i4);
        lst.add(i5);
        lst.add(i6);

        System.out.println("\n------------TEST getList()-------------\n");
        System.out.println(lst.getList(i1));
        System.out.println(lst.getList(i5));

        System.out.println("\n------------TEST remove()-------------\n");
        System.out.println(lst);
        System.out.println("Removing the point : " + i6);
        lst.remove(i6);
        System.out.println(lst);

        System.out.println("\n------------TEST get()-------------\n");
        Predicate<Integer> pr1 = x -> x == 0;
        Predicate<Integer> pr2 = x -> x == 1;
        Predicate<Integer> pr3 = x -> x == 2 || x == 3;
        Predicate<Integer> pr4 = x -> x == 6;
        System.out.println(lst.get(pr1));
        System.out.println(lst.get(pr2));
        System.out.println(lst.get(pr3));
        System.out.println(lst.get(pr4));

        System.out.println("\n------------- END QUESTION 2 -------------");

    }

    public static void main(String[] args) {
        Question1();
        Question2();
    }
}

//=======================================================
// class int
class Point {
    private int x, y;

    Point(int a, int b) {
        x = a;
        y = b;
    }

    public int x() {
        return x;
    }

    public int y() {
        return y;
    }

    public String toString() {
        return "(" + x + "," + y + ")";
    }

    public int hashCode() {
        int result = x;
        result = 31 * result + y;
        return result;
    }
}


//End class int
//=======================================================
//HashTable class
class MyHashList<E> implements Iterable<E> {
    private ArrayList<LinkedList<E>> table;

    public MyHashList(int n) {
        // n = the number of lists to create -
        // it does not limit the number of elements in the table
        table = new ArrayList<>();
        for (int j = 0; j < n; j++)
            table.add(new LinkedList<>());
    }

    private int hashC(E x) {
        int k = x.hashCode();
        //an alternative is to mask the minus using
        //int k = x.hashCode() & 0x7fffffff;
        return (Math.abs(k % table.size()));
    }

    public void add(E x) {
        int index = hashC(x);
        table.get(index).addFirst(x);
    }

    public boolean contains(E x) {
        int index = hashC(x);
        return (table.get(index).contains(x));
    }

    public boolean remove(E x) {
        int index = hashC(x);
        return table.get(index).remove(x);
    }

    public int size() {
        int count = 0;
        for (LinkedList<E> aTable : table)
            count += aTable.size();
        return count;
    }

    public Iterator<E> iterator() {
        ArrayList<E> items = new ArrayList<E>();
        int ind = 0;
        while (ind < table.size()) {
            items.addAll(table.get(ind));
            ind++;
        }
        return items.iterator();
    }

    public String toString() {
        return table.toString();
    }

    //==================================================================
    //Methods that provide information about the state of the hashtable
    public double percentUsed() {
        int count = 0;
        for (LinkedList<E> aTable : table) {
            if (aTable.size() > 0)
                count++;
        }
        return count * 100.0 / table.size();
    }

    public int largestBucket() {
        int max = 0;
        for (LinkedList<E> aTable : table) {
            int k = aTable.size();
            if (k > max)
                max = k;
        }
        return max;
    }

    public int smallestBucket() {
        int min = table.get(0).size();
        for (int j = 1; j < table.size(); j++) {
            int k = table.get(j).size();
            if (k < min)
                min = k;
        }
        return min;
    }

    public int[] listSizes() {
        int n = this.largestBucket();
        int d[] = new int[n + 1];
        for (int j = 0; j < d.length; j++)
            d[j] = 0;
        for (LinkedList<E> aTable : table) {
            int m = aTable.size();
            d[m] = d[m] + 1;
        }
        return d;
    }

    public int empty() {
        int count = 0;
        for (LinkedList<E> aTable : table)
            if (aTable.size() == 0)
                count++;
        return count;
    }
    //==================================================================
    // Methods for Question 2

    public LinkedList<E> getList(E x) {
        return table.get(hashC(x));
    }

    public void remove(List<E> ls) {
        for (E x : ls)
            table.get(hashC(x)).remove(x);
    }

    List<E> get(Predicate<E> pr) {
        List<E> points = new ArrayList<E>();

        for (LinkedList<E> list : table) {
            for (E x : list) {
                if (pr.test(x))
                    points.add(x);
            }
        }

        return points;
    }
}