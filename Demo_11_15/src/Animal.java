public class Animal {
    String name;

    int age;

    public Animal(String name, int age) {
        super();
        this.name = name;
        this.age = age;
    }

    public Animal() {
    }

    public void eat() {
        System.out.println(this.name + " is eating food.");
    }
}
