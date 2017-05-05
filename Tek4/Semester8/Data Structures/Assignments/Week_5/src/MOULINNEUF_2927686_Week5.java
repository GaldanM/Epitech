/*
  Student name: MOULINNEUF Galdan

  Student number: 2927686
 */
 /*
 For Assignment 5 please complete the methods listed below for class LinkedListHT. In each case the comment
 inserted in the method describes its purpose.
 */

import java.util.Arrays;

public class MOULINNEUF_2927686_Week5 {
    public static void main(String[] args) {
        //Test code here=========================================
        LinkedListHT list1 = new LinkedListHT();
        LinkedListHT list2 = new LinkedListHT();

        list1.addHead(3);
        list1.addHead(2);
        list1.addHead(1);
        System.out.println(list1.toString());

        list2.addTail(6);
        list2.addTail(3);
        list2.addTail(5);
        list2.addTail(4);
        System.out.println(list2.toString());

        list1.addTail(list2);
        System.out.println(list1.size());
        System.out.println(list1.toString());

        list1.delHead();
        System.out.println(list1.toString());
        list1.delTail();
        System.out.println(list1.toString());

        System.out.println(list1.sum());
        System.out.println(list1.count(1));
        System.out.println(list1.count(5));

        list1.sort();
        System.out.println(list1.toString());

        list1.reverse();
        System.out.println(list1.toString());

        System.out.println(list1.equals(list2));
        System.out.println(list1.equals(list1));
        System.out.println(list1.equals(new LinkedListHT()));
        System.out.println(list1.equals(""));
        //======================================================
    }
}

class LinkedListHT {
    private Node head = null;
    private Node tail = null;

    public void addTail(int x) {
        //add at tail
        Node nw = new Node(x);
        if (head == null) {
            head = nw;
            tail = nw;
        } else {
            tail.setNext(nw);
            tail = nw;
        }
    }

    public void addTail(LinkedListHT lst) {
        //add given list to tail of existing list
        int[] list = lst.toArray();
        for (int i : list)
            this.addTail(i);
    }

    public void addHead(int x) {
        //insert x at head of list
        Node nw = new Node(x);
        if (head == null) {
            head = nw;
            tail = nw;
        } else {
            nw.setNext(head);
            head = nw;
        }
    }

    public int[] toArray() {
        Node k = head;
        int i = 0;
        int[] arr = new int[this.size()];

        while (k != null) {
            arr[i] = k.data;
            k = k.next();
            i += 1;
        }
        return (arr);
    }

    public void sort() {
        //sort elements in list
        int[] toSort = this.toArray();
        Arrays.sort(toSort);
        this.head = null;
        this.tail = null;
        for (int i : toSort)
            this.addTail(i);
    }

    public int size() {
        Node k = head;
        int size = 0;
        while (k != null) {
            size += 1;
            k = k.next();
        }
        return (size);
    }

    public void delHead() {
        //remove element at head of list
        if (head != null)
            head = head.next();
    }

    public void delTail() {
        //remove element at tail of list
        Node k = head;
        if (k != null) {
            while (k.next() != tail)
                k = k.next();
            tail = k;
            tail.setNext(null);
        }
    }

    public int sum() {
        //calculate sum of values in the list
        Node k = head;
        int res = 0;
        if (k != null) {
            while (k != null) {
                res += k.data;
                k = k.next();
            }
        }
        return (res);
    }

    public int count(int x) {
        //count number of occurrences of x in list
        Node k = head;
        int res = 0;
        if (k != null) {
            while (k != null) {
                if (k.data == x)
                    res += 1;
                k = k.next();
            }
        }
        return (res);
    }

    public void reverse() {
        //reverse the order of the lements in the list
        int[] arr = this.toArray();
        head = null;
        tail = null;
        for (int i : arr)
            this.addHead(i);
    }

    public boolean equals(Object ob) {
        // method to test this list with another list for equality
        // Two lists equal if they have the same size and corresponding
        // values are equal
        return getClass() == ob.getClass() && (this.toString().equals(ob.toString()));
    }

    public boolean contains(int x) {
        Node k = head;
        boolean found = false;
        while (k != null && !found) {
            if (k.data() == x)
                found = true;
            else k = k.next();
        }
        return found;
    }

    public void remove(int x) {
        Node k = head;
        Node bk = head;
        boolean found = false;
        while (k != null && !found) {
            if (k.data() == x)
                found = true;
            else {
                bk = k;
                k = k.next();
            }
        }
        if (found) {
            if (k == head)
                head = k.next();
            else if (k == tail) {
                bk.setNext(null);
                tail = bk;
            } else
                bk.setNext(k.next());
        }
    }

    public String toString() {
        if (head == null)
            return "[]";
        StringBuilder s = new StringBuilder("[");
        Node k = head;
        while (k.next() != null) {
            s.append(k.data()).append(", ");
            k = k.next();
        }
        s.append(k.data()).append("]");
        return s.toString();
    }

    private class Node {
        int data;
        Node next;

        public Node(int x) {
            data = x;
            next = null;
        }

        public Node next() {
            return next;
        }

        public void setNext(Node p) {
            next = p;
        }

        public void set(int x) {
            data = x;
        }

        public int data() {
            return data;
        }
    }
}
