package basicLevel;

import java.util.Scanner;

//1011 A+B 和 C （15 分）
//        给定区间 [−2​31,2 31] 内的 3 个整数 A、B 和 C，请判断 A+B 是否大于 C。
//
//        输入格式：
//        输入第 1 行给出正整数 T (≤10)，是测试用例的个数。随后给出 T 组测试用例，每组占一行，顺序给出 A、B 和 C。整数间以空格分隔。
//
//        输出格式：
//        对每组测试用例，在一行中输出 Case #X: true 如果 A+B>C，否则输出 Case #X: false，其中 X 是测试用例的编号（从 1 开始）。
//
//        输入样例：
//        4
//        1 2 3
//        2 3 4
//        2147483647 0 2147483646
//        0 -2147483648 -2147483647
//        输出样例：
//        Case #1: false
//        Case #2: true
//        Case #3: true
//        Case #4: false
public class T1011 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int T = in.nextInt();
        int i = 1;
        while (i <= T){
            double a = in.nextDouble();
            double b = in.nextDouble();
            double c = in.nextDouble();
            System.out.println("Case #" + i + ": " +((a+b) - c < 0.000000000000001 ?"false" : "true"));
            i++;
        }
    }
}
