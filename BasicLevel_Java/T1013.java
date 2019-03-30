package basicLevel;
//1013 数素数 （20 分）
//        令 P
//        ​i
//        ​​  表示第 i 个素数。现任给两个正整数 M≤N≤10
//        ​4
//        ​​ ，请输出 P
//        ​M
//        ​​  到 P
//        ​N
//        ​​  的所有素数。
//
//        输入格式：
//        输入在一行中给出 M 和 N，其间以空格分隔。
//
//        输出格式：
//        输出从 P
//        ​M
//        ​​  到 P
//        ​N
//        ​​  的所有素数，每 10 个数字占 1 行，其间以空格分隔，但行末不得有多余空格。
//
//        输入样例：
//        5 27
//        输出样例：
//        11 13 17 19 23 29 31 37 41 43
//        47 53 59 61 67 71 73 79 83 89
//        97 101 103

import java.util.Scanner;

public class T1013 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int[] num  = new int[10005];
        int M = in.nextInt();
        int N = in.nextInt();
        int i,j = 0;
        int k;
        for (i = 2 ;j <= N ;i++){
            double n = Math.sqrt(i);
            for (k = 2;k <= n;k++){
                if (i % k == 0)
                    break;
            }
            if (k > n){
                num[j] = i;
                j++;
            }
        }
        int count = 0;
        for (i = M - 1 ; i < N; i++){
            if (!(count % 10 == 0 )){
                System.out.print(" ");
            }
            System.out.print(num[i]);
            count++;
            if (count % 10 == 0){
                System.out.println();
            }

        }
    }
}
