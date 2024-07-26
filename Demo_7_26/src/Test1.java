class Point {
    double _1;
    double _2;

    public static Point makePointXY(double x, double y) {
        Point p = new Point();
        p.set_1(x);
        p.set_2(y);
        return p;
    }

    public static Point makePointRA(double r, double a) {
        Point p = new Point();
        p.set_1(r);
        p.set_2(a);
        return p;
    }

    public void set_1(double _1) {
        this._1 = _1;
    }

    public void set_2(double _2) {
        this._2 = _2;
    }
}

public class Test1 {
    public static void main(String[] args) {
        Point p = Point.makePointXY(3, 5);
        System.out.println(p._1 + " " + p._2);

    }
}