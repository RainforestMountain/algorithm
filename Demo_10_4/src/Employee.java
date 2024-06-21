public class Employee extends People {
    public double salary;

    public Employee(String name, int age, double salary) {
        super(name, age);
        this.salary = salary;
    }

    public double computeSalary(int hours, double rate) {
        double salary = hours * rate;
        return this.salary + salary;
    }
}