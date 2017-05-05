/*
 * Student name: MOULINNEUF Galdan
 * Student number: 2927686
 */

import java.util.*;

public class MOULINNEUF_2927686_Week6 {
    public static void main(String[] args) {
        MyStack<String> stk = new MyStack<>();
        stk.push(" !");
        stk.push(" World");
        stk.push("Hello");

        System.out.println(stk.empty());
        System.out.print(stk.top());
        stk.pop();
        System.out.print(stk.top());
        stk.pop();
        System.out.println(stk.top());
        stk.pop();
        System.out.println(stk.empty() + "\n");

        // -------------------------------------- //

        MyQueue<String> qu = new MyQueue<>();
        qu.join("Hello ");
        qu.join("World ");
        qu.join("!");

        System.out.println(qu.contains("Hello "));
        System.out.println(qu.contains("olleH"));
        System.out.println(qu.empty());
        System.out.println(qu.toString());
        System.out.print(qu.top());
        qu.leave();
        System.out.print(qu.top());
        qu.leave();
        System.out.println(qu.top());
        qu.leave();
        System.out.println(qu.empty());
    }
}

interface Stack<E> {
    boolean push(E x);

    boolean pop();

    E top();

    boolean empty();

    boolean full();

    Iterator<E> iterator();
}

interface Queue<T> {
    boolean join(T x);

    T top();

    boolean leave();

    boolean full();

    boolean empty();

    String toString();

    boolean contains(T x);

    Iterator<T> iterator();
}

class MyStack<E> implements Stack<E> {
    private ArrayList<E> arrayList = new ArrayList<>();

    @Override
    public boolean push(E x) {
        this.arrayList.add(x);
        return true;
    }

    @Override
    public boolean pop() {
        this.arrayList.remove(this.arrayList.size() - 1);
        return true;
    }

    @Override
    public E top() {
        return this.arrayList.get(this.arrayList.size() - 1);
    }

    @Override
    public boolean empty() {
        return this.arrayList.isEmpty();
    }

    @Override
    public boolean full() {
        return false;
    }

    //TODO: THIS
    @Override
    public Iterator<E> iterator() {
        return this.arrayList.iterator();
    }
}

class MyQueue<T> implements Queue<T> {
    private ArrayDeque<T> arrayDeque = new ArrayDeque<>();

    @Override
    public boolean join(T x) {
        this.arrayDeque.addLast(x);
        return true;
    }

    @Override
    public T top() {
        return this.arrayDeque.getFirst();
    }

    @Override
    public boolean leave() {
        this.arrayDeque.removeFirst();
        return true;
    }

    @Override
    public boolean full() {
        return false;
    }

    @Override
    public boolean empty() {
        return this.arrayDeque.isEmpty();
    }

    @Override
    public String toString() {
        StringBuilder str = new StringBuilder();
        for (T item : this.arrayDeque) {
            str.append(item.toString());
        }
        return str.toString();
    }

    @Override
    public boolean contains(T x) {
        for (T item : this.arrayDeque) {
            if (item == x)
                return true;
        }
        return false;
    }

    //TODO : THIS
    @Override
    public Iterator<T> iterator() {
        return this.arrayDeque.iterator();
    }
}