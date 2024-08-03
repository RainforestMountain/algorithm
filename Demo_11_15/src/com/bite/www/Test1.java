package com.bite.www;

class A {
    public A() {
        System.out.println("A");
    }

    public A fun() {
        return null;
    }

    public static void print() {
        System.out.println("?");
    }

}

class B extends A {
    public B() {
        super();
        System.out.println("B");
    }

    @Override
    public B fun() {
        return new B();
    }
}

public class Test1 {
    public static void main(String[] args) {
        B b = new B();
        A a = b;

        b.print();
//        a.fun1();
//        b.fun2();
//        a.fun3();
    }
}