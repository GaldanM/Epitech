/*
 * Student name: Galdan MOULINNEUF
 *
 * Student number: 2927686

 */

public class Assignment1_2017 {
    public static void main(String args[]) {
        //test print
        print(1, 2);
        print(1, 1);
        print(1, 9);
        print(5, 10);
        print(-10, 10);
        //========================================
        //test sum
        System.out.println(sum(3, 5));
        System.out.println(sum(2, 6));
        System.out.println(sum(3, 7));
        //========================================
        //test printBinary
        printBinary(11);
        printBinary(64);
        //========================================
    }

    private static void print(int a, int b) { //assume a <= b
        System.out.print(a);
        if (a == b) {
            System.out.println("");
        } else {
            System.out.print(" ");
            print(a + 1, b);
        }
    }

    private static int sum(int a, int b) {
        return (sumTail(a, b, a));
    }

    private static int sumTail(int a, int b, int acc) {
        if (a == b)
            return acc;
        else
            return (sumTail(a + 1, b, a + acc + 1));
    }

    private static void printBinary(int x) {
        if (x == 0) {
            System.out.println();
        } else {
            printBinary(x / 2);
            System.out.print(x % 2);
        }
    }
}