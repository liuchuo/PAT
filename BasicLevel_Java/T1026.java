package basicLevel;


//1026 程序运行时间 （15 分）
//        要获得一个 C 语言程序的运行时间，常用的方法是调用头文件 time.h，其中提供了 clock() 函数，可以捕捉从程序开始运行到 clock() 被调用时所耗费的时间。这个时间单位是 clock tick，即“时钟打点”。同时还有一个常数 CLK_TCK，给出了机器时钟每秒所走的时钟打点数。于是为了获得一个函数 f 的运行时间，我们只要在调用 f 之前先调用 clock()，获得一个时钟打点数 C1；在 f 执行完成后再调用 clock()，获得另一个时钟打点数 C2；两次获得的时钟打点数之差 (C2-C1) 就是 f 运行所消耗的时钟打点数，再除以常数 CLK_TCK，就得到了以秒为单位的运行时间。
//        这里不妨简单假设常数 CLK_TCK 为 100。现给定被测函数前后两次获得的时钟打点数，请你给出被测函数运行的时间。
//        输入格式：
//        输入在一行中顺序给出 2 个整数 C1 和 C2。注意两次获得的时钟打点数肯定不相同，即 C1 < C2，并且取值在 [0,10
//        ​7
//        ​​]。
//        输出格式：
//        在一行中输出被测函数运行的时间。运行时间必须按照 hh:mm:ss（即2位的 时:分:秒）格式输出；不足 1 秒的时间四舍五入到秒。
//        输入样例：
//        123 4577973
//        输出样例：
//        12:42:59

import java.util.Scanner;

public class T1026 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int c1 = in.nextInt();
        int c2 = in.nextInt();
        //考虑四舍五入
        int sum = (c2 - c1 + 50) / 100;
        int h = sum / 3600;
        sum = sum % 3600;
        int m = sum / 60;
        int s = sum % 60;
        System.out.printf("%02d:%02d:%02d",h,m,s);
    }
}
