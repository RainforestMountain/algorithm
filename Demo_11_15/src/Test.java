public class Test {
    public static void func(Animal animal) {
        animal.eat();
    }

    public static void main(String[] args) {
        Animal animal1 = new Dog();
        Animal animal2 = new Giraffe();
        //多态
        Test.func(animal1);
        Test.func(animal2);
    }
}
