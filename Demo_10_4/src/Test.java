import java.util.Arrays;

public class Test {
    public static void main(String[] args) {
        var emp = new Employee("ming", 25, 6000);
        System.out.println(emp.toString());
        People p = emp;
        System.out.println(p.toString());
        p.sayHello();
        emp = (Employee) p;
        System.out.println(emp.computeSalary(5, 50));
//        var c = new People("li", 25);//编译错误
//        Employee T = (Employee) c;
        //父类对象必须由子类构造方法创建

        People people = new People("li", 26);

        if (people instanceof Employee) {
            Employee employee = (Employee) people;  // 进行类型转换
            // ...
        } else {
            System.out.println("无法转换");
            // 处理类型不匹配的情况
        }

    }
}