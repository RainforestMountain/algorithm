public class People {
    public String name;
    public int age;


    public People(String name, int age) {
        this.name = name;
        this.age = age;
    }

    public void sayHello() {
        System.out.println("Hello, my name is " + name);
    }
}