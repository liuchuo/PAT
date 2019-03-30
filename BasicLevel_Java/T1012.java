package basicLevel;
//给定一系列正整数，请按要求对数字进行分类，并输出以下 5 个数字：
//
//        A
//        ​1
//        ​​  = 能被 5 整除的数字中所有偶数的和；
//        A
//        ​2
//        ​​  = 将被 5 除后余 1 的数字按给出顺序进行交错求和，即计算 n
//        ​1
//        ​​ −n
//        ​2
//        ​​ +n
//        ​3
//        ​​ −n
//        ​4
//        ​​ ⋯；
//        A
//        ​3
//        ​​  = 被 5 除后余 2 的数字的个数；
//        A
//        ​4
//        ​​  = 被 5 除后余 3 的数字的平均数，精确到小数点后 1 位；
//        A
//        ​5
//        ​​  = 被 5 除后余 4 的数字中最大数字。
//        输入格式：
//        每个输入包含 1 个测试用例。每个测试用例先给出一个不超过 1000 的正整数 N，随后给出 N 个不超过 1000 的待分类的正整数。数字间以空格分隔。
//
//        输出格式：
//        对给定的 N 个正整数，按题目要求计算 A
//        ​1
//        ​​ ~A
//        ​5
//        ​​  并在一行中顺序输出。数字间以空格分隔，但行末不得有多余空格。
//
//        若其中某一类数字不存在，则在相应位置输出 N。
//
//        输入样例 1：
//        13 1 2 3 4 5 6 7 8 9 10 20 16 18
//        输出样例 1：
//        30 11 2 9.7 9
//        输入样例 2：
//        8 1 2 4 5 6 7 9 16
//        输出样例 2：
//        N 11 2 N 9

import java.util.Scanner;

public class T1012 {
    static int [] num = new int[1005];
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int N = in.nextInt();
        int i;
        int a1 = 0,a2 = 0,a3 = 0,a5 = -1;
        int a4 = 0;
        int cout4 = 0;
        int flag = 1;
        boolean a22 = false;
        for (i = 0; i < N ;i++){
            num[i] = in.nextInt();
            if (num[i] % 5 == 0 && num[i] % 2 == 0){
                a1 += num[i];
            }
            if (num[i] % 5 == 1){
                a2 += (num[i] * flag);
                flag = flag * (-1);
                a22 = true;
            }
            if (num[i] % 5 == 2){
                a3++;
            }
            if (num[i] % 5 == 3 ){
                cout4 ++;
                a4 += num[i];
            }
            if (num[i] % 5 == 4){
                if (a5 < num[i]){
                    a5 = num[i];
                }
            }
        }
        if (a1 != 0){
            System.out.print(a1 + " ");
        }else {
            System.out.print("N ");
        }
        if (a22){
            System.out.print(a2 + " ");
        }else {
            System.out.print("N ");
        }
        if (a3 != 0){
            System.out.print(a3 + " ");
        }else {
            System.out.print("N ");
        }
        if (cout4 != 0){
            System.out.printf("%.1f",(1.0 * a4 / cout4));
            System.out.print(" ");
        }else {
            System.out.print("N ");
        }
        if (a5 != -1){
            System.out.print(a5);
        }else {
            System.out.print("N");
        }

    }
}
