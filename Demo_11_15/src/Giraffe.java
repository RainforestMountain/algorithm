public class Giraffe extends Animal {
    public Giraffe() {
        super("G", 4);
    }

    @Override
    public void eat() {
        System.out.println(this.name + " is eating grass.");
    }

}
