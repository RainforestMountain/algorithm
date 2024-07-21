package org.apache;

import java.io.UnsupportedEncodingException;
import java.lang.*;

public class StringClass {
    public StringClass(java.lang.String str1) {

    }

    public static void main(String[] args) {
        //1.创建string类对象
//        var str1 = "hello world";
//        var str2 =new String();
//        char data[]={'j','a','v','a',' ','i','s',' ','c','o','o','l'};
//        var str3 = new String(data);
//        var str4 = new String(str3+" nice");
//        System.out.println(str1);
//        System.out.println(str2);
//        System.out.println(str3);
//        System.out.println(str4);

        //2.字符串基本操作
//        var str1=new String("java programmer is cool  ");
//        System.out.println(str1.length());
//        //通过下标产生子串,两个方法重载
//        System.out.println(str1.substring(5,10));
//        System.out.println(str1.substring(5));
//        //返回去掉前后空白字符串的字符串
//        System.out.println(str1.trim());
//        //判断是否为空
//        System.out.println(str1.isEmpty());
//        //连接调用字符串与参数字符串
//        System.out.println(str1.concat("and java is a good language"));
//        //更换字符串的单种字符
//        System.out.println(str1.replace('j','J'));
//        //返回指定位置字符
//        System.out.println(str1.charAt(6));

        //3.字符串的查找
//        var s=new String("this is a java string");
//        System.out.println(s.length());
//        //查找字符第一次出现的位置,错误返回-1
//        System.out.println(s.indexOf('a'));
//        //查找一个字符串str在调用字符串中第一次出现的位置,错误返回-1
//        System.out.println(s.indexOf("string"));
//        //查找字符最后一次出现的位置,错误返回-1
//        System.out.println(s.lastIndexOf('g'));
//        //查找字符串str从fromIndex(调用字符串的下标,下标从0开始)开始第一次出现的位置,错误返回-1
//        System.out.println(s.indexOf("bing",9));
//        //查找字符ch到endIndex为止最后一次出现的位置,错误返回-1
//        System.out.println(s.lastIndexOf('s',12));
//        //查找字符串str最后一次出现的位置,错误返回-1
//        System.out.println(s.lastIndexOf("str"));
//        //查找字符串str到endIndex为止最一次出现的位置,错误返回-1
//        System.out.println(s.lastIndexOf("java",10));


        //4.字符串比较
//        var s1 = new String("java world");
//        var s2 = new String("java world");
//        var s3 = new String("java WOrld");
//        //比较字符串是否相等，不忽略大小写
//        System.out.println(s1.equals(s2));
//        //比较字符串是否相等，忽略大小写
//        System.out.println(s1.equalsIgnoreCase(s3));
//        //==比较的是s1和s2的引用
//        System.out.println(s1 == s2);
//        //字面量即常量存储在静态区，只有一个副本，所以赋值给s1,s2的引用相同
//        var s4 = "hello";
//        var s5 = "hello";
//        System.out.println(s4 == s5);
//        //字符串大小的比较,返回第一个不相等的字符的差值(s1-s2)，如果全部相等返回0
//        System.out.println(s1.compareTo(s3));
//        System.out.println(s1.compareTo(s2));

//        //5.字符串转换为字符数组
//        var s = new String("this is a test");
//        //将字符串中的字符转换成字符数组
//        char[] chars = s.toCharArray();
//        System.out.println(chars[0]);
//        System.out.println(chars);
//        //将字符串中从起始位置结束位置之间的字符复制到字符数组destination中，最后一个参数为目标数组的下标
//        char[] destination = new char[30];
//        s.getChars(0, s.length(), destination, 5);
//        //使用平台的字符集将字符串将字符串编码成字节序列并将结果存储到字节数组中,两个方法重载
//        byte[] bytes = s.getBytes();
//        System.out.println(bytes);
//        for (byte i : bytes) {
//            System.out.print(i + " ");
//        }
//        byte[] temp = new byte[0];
//        try {
//            temp = s.getBytes("java");
//        } catch (UnsupportedEncodingException e) {
//            throw new RuntimeException(e);
//        }
//        System.out.println(temp);
//        for (byte i : bytes) {
//            System.out.print(i + " ");
//        }

        //6.字符串拆分与组合
//        var str = new String("c++ programmer,java programmer");
//        //根据给定的正则表达式(regex)将字符串拆分成字符串数组
//        var src = str.split("[,]");
//        for (String i : src) {
//            System.out.println(i);
//        }
//        //返回字符串是否与给定的正则表达式匹配
//        System.out.println(str.matches("，java"));
//        //连接字符串，第一个参数为分隔符，后面的参数为字符串数组
//        var match = String.join("", "c:", "\\", "test", "_10_14");
//        System.out.println(match);
//        String[] seasons = {"spring", "summer", "autumn", "winter"};
//        var dest = String.join("-", seasons);
//        System.out.println(dest);
        //7.String对象的不变性,修改对原字符串没有影响，只是修改了引用
//        var s = new String("Hello,world");
//        s.replace('o', 'A');
//        System.out.println(s);
//        s = s.substring(0, 6).concat("Java");
//        s.toUpperCase();
//        System.out.println(s);
        //8.命令行参数
//        System.out.println(args[0] + " " + args[1] + " " + args[2]);
        //9.格式化输出printf(String format, Object... args);

        //10.创建StringBuilder对象
//        var s = "hello kong";
//        var str = new StringBuilder("Hello");
//        System.out.println("str.length=" + str.length());
//        System.out.println("str.capacity=" + str.capacity());
//        str = new StringBuilder("hello,java programmer");
//        System.out.println("str.length=" + str.length());
//        System.out.println("str.capacity=" + str.capacity());
//        CMBAnalysis cmbAnalysis = new CMBAnalysis();
////利用java反射机制获取
//        Field[] fields = cmbAnalysis.getClass().getDeclaredFields();
//        for (int k = 0; k < fields.length; k++) {
//            String name = fields[k].getName();
//            System.out.println(name);
//        }

    }
}
