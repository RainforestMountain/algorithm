////import java.util.Scanner;
////
////public class Main {
////
////    public static void main(String[] args) {
////        Scanner scanner = new Scanner(System.in);
////        while (scanner.hasNextInt()) {
////            int x = scanner.nextInt();
////            int y = scanner.nextInt();
////            int z = scanner.nextInt();
////            Sub sub = new Sub(x, y, z);
////            System.out.println(sub.calculate());
////        }
////    }
////
////}
////
////class Base {
////
////    private int x;
////    private int y;
////
////    public Base(int x, int y) {
////        this.x = x;
////        this.y = y;
////    }
////
////    public int getX() {
////        return x;
////    }
////
////    public int getY() {
////        return y;
////    }
////
////}
////
////class Sub extends Base {
////
////    private int z;
////
////    public Sub(int x, int y, int z) {
////
////        //write your code here
////        super(x,y);
////        this.z=z;
////    }
////
////    public int getZ() {
////        return z;
////    }
////
////    public int calculate() {
////        return super.getX() * super.getY() * this.getZ();
////    }
////
////}
////
//import java.util.Scanner;
//
//public class Main {
//
//    public static void main(String[] args) {
//        // Sub是需要你定义的子类
//        Base base = new Sub();
//
//        Scanner scanner = new Scanner(System.in);
//        while (scanner.hasNextInt()) {
//            int x = scanner.nextInt();
//            int y = scanner.nextInt();
//            base.setX(x);
//            base.setY(y);
//            System.out.println(base.calculate());
//        }
//    }
//
//}
//
//abstract class Base {
//
//    private int x;
//    private int y;
//
//    public int getX() {
//        return x;
//    }
//
//    public void setX(int x) {
//        this.x = x;
//    }
//
//    public int getY() {
//        return y;
//    }
//
//    public void setY(int y) {
//        this.y = y;
//    }
//
//    public int calculate() {
//        if (avg() == 0) {
//            return 0;
//        } else {
//            return sum() / avg();
//        }
//    }
//
//    /**
//     * 返回x和y的和
//     */
//    public abstract int sum();
//
//    /**
//     * 返回x和y的平均值
//     */
//    public abstract int avg();
//
//}
//
//class Sub extends Base {
//
//    //write your code here......
//    @Override
//    public int sum(){
//        return getX()+getY();
//    }
//    @Override
//    public int avg()
//    {
//        return (getX()+getY())/2;
//    }
//}
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        while (scanner.hasNextInt()) {
            int x = scanner.nextInt();
            int y = scanner.nextInt();
            Sub sub = new Sub(x, y);
            sub.calculate();
        }
    }

}

class Base {

    private int x;
    private int y;

    public Base(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }

    public void calculate() {
        System.out.println(getX() * getY());
    }

}

class Sub extends Base {

    //write your code here......
    public Sub(int x,int y) {
        super(x, y);
    }
    public void calculate()
    {
        int x=super.getX();
        int y=super.getY();
        if(y==0)
        {
            System.out.println("error");
            return;
        }
        System.out.println(x/y);
    }

}