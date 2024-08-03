public class Dog extends Animal {
    String color;

    public Dog() {
        super("D", 4);
        color = "white";
    }

    @Override
    public String toString() {
        return this.name + " " + this.age + " " + this.color;
    }

    public static void main(String[] args) {
        Dog D = new Dog();

        System.out.println(D);
    }

    @Override
    public void eat() {
        System.out.println(this.name + " is eating meat.");
    }
}
