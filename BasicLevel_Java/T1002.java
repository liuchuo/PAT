package basicLevel;

//1002 写出这个数 （20 分）
//        读入一个正整数 n，计算其各位数字之和，用汉语拼音写出和的每一位数字。
//
//        输入格式：
//        每个测试输入包含 1 个测试用例，即给出自然数 n 的值。这里保证 n 小于 10
//        ​100
//        ​​ 。
//
//        输出格式：
//        在一行内输出 n 的各位数字之和的每一位，拼音数字间有 1 空格，但一行中最后一个拼音数字后没有空格。
//
//        输入样例：
//        1234567890987654321123456789
//        输出样例：
//        yi san wu

import java.util.Scanner;

public class T1002 {
    public static void main(String[] args) {
        String str = new Scanner(System.in).nextLine();
        char[] chars = str.toCharArray();
        int sum = 0;
        for (int i = 0;i < chars.length ; i++){
            sum += chars[i]-'0';
        }
        char[] c = (sum + "").toCharArray();
        boolean flag = false;
        for (int i = 0;i < c.length ;++i){
            if (flag) {
                System.out.print(" ");
            }
            out(c[i]);
            flag = true;
        }

    }
    private static void out(char c){
        switch (c){
            case '1':
                System.out.print("yi");
                break;
            case '2':
                System.out.print("er");
                break;
            case '3':
                System.out.print("san");
                break;
            case '4':
                System.out.print("si");
                break;
            case '5':
                System.out.print("wu");
                break;
            case '6':
                System.out.print("liu");
                break;
            case '7':
                System.out.print("qi");
                break;
            case '8':
                System.out.print("ba");
                break;
            case '9':
                System.out.print("jiu");
                break;
            case '0':
                System.out.print("ling");
                break;

        }
    }
}
